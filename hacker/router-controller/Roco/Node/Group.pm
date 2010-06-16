package Roco::Node::Group;

use strict;
use vars qw/@ISA/;
use Roco::Node;

our $opt_verbtitle      = __PACKAGE__;
our $opt_verbtime       = 0;
our $opt_verbose        = 1;

@ISA    = qw(Roco::Node);

sub create {
    my ($self, $frame) = @_;
    $frame->Label(
        -text => 'Group: '.$self->path,
        -justify => 'left')->pack(
        -side => 'top', -anchor => 'w');
}

1