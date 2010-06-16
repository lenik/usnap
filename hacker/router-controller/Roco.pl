#!/usr/bin/perl

use strict;
use cmt::util;
use cmt::vcs;
# use cmt::winuser;
use Data::Dumper;
use Getopt::Long;
use Roco::Dev;
use Roco::Dev::WebRouter;
use Roco::Misc;
use Roco::Node::Group;
use Roco::Node::Instance;
use Roco::Node::Model;
use Roco::Node::Profile;
use Roco::Node::ReadCode;
use Tk;
use Tk::Adjuster;
use Tk::BrowseEntry;
use Tk::Button;
use Tk::Dialog;
use Tk::DialogBox;
use Tk::Frame;
use Tk::LabEntry;
use Tk::Listbox;
use Tk::Pane;
use Tk::Radiobutton;
use Tk::HList;
use Tk::Tree;
use YAML;

sub boot;
sub main;
sub info;
sub info2;
sub version;
sub help;
sub mkgui;
sub pref_box;
sub about_box;
sub add_inst_box;
sub add_inst;
sub show_inst;
sub loadprofile;
sub loadnode;
sub file_load;
sub file_save;
sub file_save_as;

our $opt_verbtitle      = 'Roco';
our $opt_verbtime       = 0;
our $opt_verbose        = 1;

my $CFG;
my $PROFILE;

my $mw;
my $tree;
my $f_detail;
my $last_panel;         # last dynamic-panel in the f_detail
my $last_inst;          # last shown inst

my $w_addinst;

sub boot {
    GetOptions('quiet|q'    => sub { $opt_verbose-- },
               'verbose|v'  => sub { $opt_verbose++ },
               'version'    => sub { version; exit },
               'help|h'     => sub { help; exit },
               );
    main;
}

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

sub version {
    my %id = parse_id('$Id: Roco.pl,v 1.8 2007-08-02 22:56:09 lenik Exp $');
    return %id if wantarray;
    print "[$opt_verbtitle] Router Controller \n";
    print "Written by Lenik,  Version $id{rev},  Last updated at $id{date}\n";
}

sub help {
    version;
    print <<"EOM";

Syntax:
        $0 <options> ...

Options:
        --quiet (q)
        --verbose (v, repeat twice give you more verbose info)
        --version
        --help (h)
EOM
}

exit boot;

sub main {
    $CFG = YAML::LoadFile('Roco.cfg')
        or die "Can't load config file Roco.cfg: $!";
    set_locale $CFG->{Locale};
    loadres;
    loadmodels;

    if (-f $CFG->{Profile}) {
        $PROFILE = YAML::LoadFile($CFG->{Profile});
            # or start blank
    } else {
        $PROFILE = parseprof {
            '.' => 'Profile',
            'all' => {
                '.' => 'Group',
            },
            'tools' => {
                '.' => 'Group',
                'readcode (embedded version)' => {
                    '.' => 'ReadCode',
                },
            },
        };
    }

    mkgui;
    loadprofile;

    MainLoop;
}

sub mkgui {
    $mw = MainWindow->new(
        -title => L 'roco.title');
    $mw->geometry('640x480');

    my $menubar = $mw->Frame(
        #-background => 'gray',
        -relief => 'raised', -borderwidth => 1)->pack(
        -side => 'top', -fill => 'x');
    my $m_file = $menubar->Menubutton(
        -text => 'File', -underline => 0)->pack(
        -side => 'left');
        $m_file->command(-label => 'Load...', -underline => 0,
            -state => 'disabled', -command => \&file_load);
        $m_file->command(-label => 'Save', -underline => 0,
            -state => 'disabled', -command => \&file_save);
        $m_file->command(-label => 'Save As...', -underline => 5,
            -state => 'disabled', -command => \&file_save_as);
        # $m_file->separator;
        # $m_file->command(-label => 'Preference...', -underline => 0, -command => \&pref_box);
        $m_file->separator;
        $m_file->command(-label => 'Exit', -underline => 1);
    my $m_help = $menubar->Menubutton(
        -text => 'Help', -underline => 0)->pack(
        -side => 'left');
        $m_help->command(-label => 'About', -underline => 0, -command => \&about_box);

    my $f_tree = $mw->Frame()->pack(
        -side => 'left', -fill => 'both',
        -padx => 5, -pady => 5);
       $f_tree->Label(-text => L 'l.routers')->pack(
        -side => 'top');
    $tree = $f_tree->Tree(
        -width => 35,
        -separator => '.', -itemtype => 'imagetext',
        -selectmode => 'single', -selectbackground => '#eeeeee')->pack(
        -side => 'top', -fill => 'both', -expand => 1);
    my $f_treectl = $f_tree->Frame()->pack(
        -side => 'bottom', -anchor => 'e');
    my $btn_add = $f_treectl->Button(
        -text => 'Add', -underline => 0)->pack(
        -side => 'left', -padx => 2);
    my $btn_del = $f_treectl->Button(
        -text => 'Delete', -underline => 0)->pack(
        -side => 'left', -padx => 2);
    $f_tree->packAdjust();
    $f_detail = $mw->Frame()->pack(
        -side => 'left', -fill => 'both', -expand => 1);

    $tree->configure(
        -browsecmd => \&show_inst,
        -command => \&show_inst,
        );
    $btn_add->configure(-command => sub {
        my $inst = add_inst_box(undef, undef,
            '192.168.2.254:80:admin:admin'
            # '192.168.1.1:80:admin:admin'
            );
        if (defined $inst) {
            my ($spec, $model, $address, $alias) = @$inst;
            my $g = $PROFILE->{'all'}->{$model};
            if (! defined $g) {
                $g = $PROFILE->{'all'}->{$model} = {};
                # $g->{'.'} =
            }
            if (length $alias == 0) {
                my $insts = $tree->info('children', 'all');
                $alias = $#$insts + 1;
            }
            my $path = 'root.all.'.$spec->{Name};
            # TODO.
            # tree_addsorted($tree, $path,
        }
    });
    $btn_del->configure(-command => sub {

    });

}

sub about_box {
    my %id = version;
    $mw->Dialog(
        -title => 'About Roco',
        -text => "Version $id{rev}, Last updated $id{date}",
        -buttons => ['OK'])->Show;
}

sub pref_box {
    my $d = $mw->DialogBox(
        -title => 'Preference',
        -buttons => ['OK', 'Cancel']);
    my $f = $d->Frame()->pack(-side => 'top', -fill => 'both', -expand => 1);
    $f->Label(
        -text => 'Nothing to configure, yet')->pack(
        -side => 'top');
    return undef if $d->Show ne 'OK';
}

sub add_inst_box {
    my ($spec, $model, $address, $alias) = @_;
    my $specs = hash2tuples(\%HIERARCH);
    my $models = [];

    my $d = $mw->DialogBox(
        -title => 'Add Instance',
        -buttons => ['OK', 'Cancel']);
    my $f = $d->Frame()->pack(-side => 'top', -fill => 'both', -expand => 1);
    my $row = 0;

    $f->Label(
        -text => 'Name(alias): ', -underline => 0)->grid(
        -row => $row, -column => 0, -sticky => 'w');
    $f->Entry(
        -textvariable => \$alias, )->grid(
        -row => $row, -column => 1, -columnspan => 2, -sticky => 'ew');

    $f->Label(
        -text => 'Spec: ', -underline => 0)->grid(
        -row => ++$row, -column => 0, -sticky => 'w');
    my $opt_spec = $f->Optionmenu(
        -options => $specs, -variable => \$spec)->grid(
        -row => $row, -column => 1, -columnspan => 2, -sticky => 'ew');

    $f->Label(
        -text => 'Model: ', -underline => 0)->grid(
        -row => ++$row, -column => 0, -sticky => 'w');
    my $opt_model = $f->Optionmenu(
        -options => $models, -variable => \$model)->grid(
        -row => $row, -column => 1, -columnspan => 2, -sticky => 'ew');

    $f->Label(
        -text => 'Address: ', -underline => 0)->grid(
        -row => ++$row, -rowspan => 2, -column => 0, -sticky => 'w');
    $f->Label(
        -text => "Address format of WebRouter: \nHOST:PORT:USERNAME:PASSWORD")->grid(
        -row => $row, -column => 1, -sticky => 'ew');
    $f->Entry(
        -textvariable => \$address, )->grid(
        -row => $row + 1, -column => 1, -sticky => 'ew');
    my $btn_probe = $f->Button(
        -text => "Probe", -underline => 0)->grid(
        -row => $row, -rowspan => 2, -column => 2, -columnspan => 2,
        -padx => 2, -sticky => 'ewns');

    $opt_spec->configure(-command => sub {
        my $models = [];
        $models = $spec->{Models} if defined $spec;
        $opt_model->configure(-options => $models);
    });

    $btn_probe->configure(-command => sub {
        my $mod = probe_webdev($address);
        if ($mod) {
            #$mw->Dialog(
            #    -title => 'Probe', -text => "Detected: $mod",
            #    -buttons => ['OK'])->Show;
            $spec = getmodel($mod);
            my $tvar = $opt_spec->cget(-textvariable);
            $$tvar = $spec->{Name};
            $model = $mod;
        } else {
            $mw->Dialog(
                -title => 'Probe', -text => "Can't determine the model of device",
                -buttons => ['OK'])->Show;
        }
    });

    return $d->Show eq 'OK'
        ? [$spec, $model, $address, $alias]
        : undef;
}

sub add_inst {
    my $inst = shift;
    my $path;
    $tree->add($path,
        -text => $inst->{Name},
        -data => $inst,
        );
}

sub show_inst {
    my $path = shift;
    my $data = $tree->info('data', $path);
    my $inst = $data->{'.'};

    $last_inst->remove if defined $last_inst;
    $last_panel->packForget if defined $last_panel;

    my $scroll = 1;
    $scroll = $inst->want_scroll if defined $inst;

    $last_panel = $scroll
        ? $f_detail->Scrolled('Frame', -scrollbars => 'se', -relief => 'groove', -borderwidth => 1)
        : $f_detail->Frame();
    $last_panel->pack(
        -fill => 'both', -expand => 1, -padx => 5, -pady => 5);
    $inst->create($last_panel) if defined $inst;
    $last_inst = $inst;
}

sub loadprofile {
    loadnode $PROFILE, 'root';
}

sub loadnode {
    my ($data, $path) = @_;
    my $node = $data->{'.'};
    my $text = defined $node ? $node->caption : undef;
    my $bitmap = defined $node ? $node->bitmap: undef;
    unless ($text) {
        ($text) = $path =~ /([^.]*)$/;
    }
    tree_addsorted($tree, $path,
        -text => $text, -bitmap => $bitmap, -data => $data);
    for (sort keys %$data) {
        next if $_ =~ /^\./;
        my $subdat = $data->{$_};
        loadnode $subdat, "$path.$_";
    }
}
