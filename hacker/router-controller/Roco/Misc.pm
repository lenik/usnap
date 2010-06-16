package Roco::Misc;

use strict;
use vars qw/@ISA @EXPORT/;
use cmt::path;
use cmt::perlsys;
use cmt::pp;
use cmt::util;
use Data::Dumper;
use DirHandle;
use Exporter;
use LWP::Simple;
use LWP::UserAgent;
use YAML qw/LoadFile/;

@ISA    = qw(Exporter);
@EXPORT = qw(%HIERARCH
             %MODELS
             loadmodels
             getmodel
             make_id
             probe_webdev
             interp_params
             set_locale
             loadres
             L
             parseprof
             tree_addsorted);

our $opt_verbtitle      = __PACKAGE__;
our $opt_verbtime       = 0;
our $opt_verbose        = 1;
our $opt_locale         = 'en';
my  $TEXT;              # locale res

our %HIERARCH;
our %MODELS;

sub info {
    return if $opt_verbose < 1;
    my $text = shift;
    print datetime.' ' if $opt_verbtime;
    print "[$opt_verbtitle] $text\n";
}

sub info2 {
    return if $opt_verbose < 2;
    my $text = shift;
    print datetime.' ' if $opt_verbtime;
    print "[$opt_verbtitle] $text\n";
}

sub loadmodels {
    my $devhome = which_package('Roco::DevDB::');
    die "Devices Database is not existed" unless -d $devhome;
    my $dh = new DirHandle($devhome);
    my @files = $dh->read;
    my $count = 0;
    for (@files) {
        next if /^\./;
        my $file = path_join($devhome, $_);
        next if -d $file;
        info2 'loading dev '.$file;
        for (LoadFile($file)) {
            for my $g (@{$_->{Globs}}) {
                push @{$_->{Patterns}}, qg $g;
            }
            $HIERARCH{$_->{Name}} = $_;
            for my $m (@{$_->{Models}}) {
                $MODELS{$m} = $_;
            }
            $count++;
        }
    }
    #info 'Hierarch: '.Dumper(\%HIERARCH);
    #info 'Models: '  .Dumper(\%MODELS);
    \%HIERARCH;
}

sub getmodel {
    my $name = shift;
    my $node = $MODELS{$name};
    if (defined $node) {
        return wantarray ? ($node, 1) : $node;
    }
    for my $dname (keys %HIERARCH) {
        my $node = $HIERARCH{$dname};
        for (@{$node->{Patterns}}) {
            if ($name =~ $_) {
                return wantarray ? ($node, 0) : $node;
            }
        }
    }
}

sub make_id {
    my $str = shift;
    $str =~ s/[^a-zA-Z0-9-]/_/g;
    return $str;
}

sub probe_webdev {
    my $addr = shift;
    my ($host, $port) = split(':', $addr);
    my $entry = "http://$host:$port/";
    my $ua = new LWP::UserAgent;
    my $resp = $ua->get($entry);
    my $auth = $resp->www_authenticate;
    if (defined $auth) {
        return $1 if ($auth =~ /realm=\"([^\"]+)\"/);
    }
    return undef;
}

sub interp_params {
    my ($model, $str, %params) = @_;
    my $modp = $model->{Parameters};

    # $XXX or ${...}
    return ppvar sub {
        my $name = shift;
        return (defined $params{$name})
            ? $params{$name}
            : $_ = $modp->{$name}->{value};
    }, $str;
}

sub set_locale {
    $opt_locale = shift;
}

sub loadres {
    $TEXT = {};
    my $resdir = which_package('res::');
    die "Can't find res-package" unless -d $resdir;
    my $dh = new DirHandle($resdir);
    my @files = $dh->read;
    for (@files) {
        next if /^\./;
        my ($loc) = /\.(\w+)$/;
        next unless $loc eq $opt_locale;
        my $file = path_join($resdir, $_);
        next if -d $file;

        info2 'loading res '.$file;
        for my $node (LoadFile($file)) {
            $TEXT->{$_} = $node->{$_} for keys %$node;
        }
    }
    $TEXT;
}

sub L {
    my $id = shift;
    my $msg = $TEXT->{$id};
    die "Invalid res id: $id isn't defined" unless defined $msg;
    sprintf($msg, @_);
}

sub parseprof {
    my $plain = shift;
    my $d = $plain->{'.'};
    if (defined $d) {
        my $class = 'Roco::Node::'.$d;
        my $inst = $class->new($plain);
        $plain->{'.'} = $inst;
    }
    for (keys %$plain) {
        next if /^\./;
        $plain->{$_}->{'..'} = $plain;
        $plain->{$_} = parseprof($plain->{$_});
    }
    return $plain;
}

sub tree_addsorted {
    my $tree = shift;
    my $path = shift;
    my ($dir, $base) = $path =~ /^(?:(.*)\.)?([^.]*)$/;
    my $before;
    if ($tree->info('exists', $dir)) {
        my $children = $tree->info('children', $dir);
        my $index = bserchi(undef, $base, $children);
        $before = $children->[$index];
    }
    # unshift @_, (-before => $before) if defined $before;
    # info "2 -before => $before";
    $tree->add($path, @_);
}

1;