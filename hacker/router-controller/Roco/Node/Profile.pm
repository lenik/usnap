package Roco::Node::Profile;

use strict;
use vars qw/@ISA/;
use YAML 'Dump';
use Roco::Node;

our $opt_verbtitle      = __PACKAGE__;
our $opt_verbtime       = 0;
our $opt_verbose        = 1;

@ISA    = qw(Roco::Node);

sub create {
    my $self = shift;
    my ($frame) = @_;
    #$frame->Label(
    #    -text => Dump($self->{PROFILE}),
    #    -justify => 'left')->pack(
    #    -side => 'top', -fill => 'both', -expand => 1);
}

1