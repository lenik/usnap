package Roco::Node::ReadCode;

use strict;
use vars qw/@ISA/;
use cmt::codec;
use cmt::util;
use Roco::Node;

sub load_codec;
sub encode;
sub decode;

our $opt_verbtitle      = __PACKAGE__;
our $opt_verbtime       = 0;
our $opt_verbose        = 1;

my $parent;
my $var_codec;
my $var_param;
my @codec_param;
my $t_src;
my $t_dst;
my $encodef;
my $decodef;

@ISA    = qw(Roco::Node);

sub create {
    my ($self, $frame) = @_;

    $parent = $frame;
    my $f_top = $frame->Frame()
        ->pack(-side => 'top', -fill => 'x', -padx => 2, -pady => 2);
    my $mnu_codec = $f_top->BrowseEntry(
        -label => 'Codec', -width => 10,
        -variable => \$var_codec)
        ->pack(-side => 'left');
    $mnu_codec->insert('end', $_) for keys %CODECS;
    my $l_param = $f_top->Label(
        -text => 'Param', -underline => 0)
        ->pack(-side => 'left');
    my $e_param = $f_top->Entry(
        -textvariable => \$var_param)
        ->pack(-side => 'left', -fill => 'x', -expand => 1);

    my $btn_encode = $f_top->Button(
        -text => 'Encode', -underline => 0,
        -command => \&encode)
        ->pack(-side => 'left', -padx => 2);
    my $btn_decode = $f_top->Button(
        -text => 'Decode', -underline => 0,
        -command => \&decode)
        ->pack(-side => 'right', -padx => 2);

    my $f_bottom = $frame->Frame()
        ->pack(-side => 'bottom', -anchor => 'e', -padx => 2, -pady => 2);
    my $btn_clear = $f_bottom->Button(
        -text => 'Clear', -underline => 0)
        ->pack(-side => 'left', -padx => 2);

    my $f_body = $frame->Frame()
        ->pack(-side => 'top', -fill => 'both', -expand => 1, -padx => 2, -pady => 2);
    $t_src = $f_body->Scrolled('Text', -scrollbars => 'e',
        -width => 6, -height => 12, -wrap => 'word', )
        ->pack(-fill => 'both', -expand => 1);
    $t_src->packAdjust();
    $t_dst = $f_body->Scrolled('Text', -scrollbars => 'se',
        -width => 6, -height => 12, -wrap => 'none', )
        ->pack(-fill => 'both', -expand => 1);

    $var_codec = 'base64';

    $btn_clear->configure(-command => sub {
        $t_src->delete('1.0', 'end');
        $t_dst->delete('1.0', 'end');
    });
}

sub load_codec {
    my $codec = $CODECS{$var_codec};
    if (! defined $codec) {
        $parent->Dialog(
            -title => 'Error',
            -text => "Codec $var_codec isn't supported",
            -buttons => ['OK'])->Show;
        return 0;
    }
    $encodef = $codec->[0];
    $decodef = $codec->[1];

    @codec_param = qsplit(qr/\s+/, $var_param);
}

sub encode {
    load_codec;
    my $src = $t_src->get('1.0', 'end');
    my $dst = $encodef->($src, @codec_param);
    $t_dst->delete('1.0', 'end');
    $t_dst->insert('end', $dst);
}

sub decode {
    load_codec;
    my $dst = $t_dst->get('1.0', 'end');
    my $src = $decodef->($dst, @codec_param);
    $t_src->delete('1.0', 'end');
    $t_src->insert('end', $src);
}

1