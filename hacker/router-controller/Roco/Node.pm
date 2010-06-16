package Roco::Node;

use strict;
use vars qw/@ISA/;
use cmt::util;
use Roco::Misc;
use Roco::Panel;

our $opt_verbtitle      = __PACKAGE__;
our $opt_verbtime       = 0;
our $opt_verbose        = 1;

@ISA    = qw(Roco::Panel);

sub init {
    my $self = shift;
    $self->{DATA} = shift;
    $self->{PARAM} = \@_;
}

sub data {
    my $self = shift;
    return $self->{DATA};
}

sub path {
    my $self = shift;
    my @path;
    my $d = $self->data;
    while (defined $d) {
        my $parent = $d->{'..'};
        my $name;
        if (defined $parent) {
            $name = hash_index($parent, $d);
            unshift @path, $name;
        }
        $d = $parent;
    }
    return join('.', @path);
}

sub caption {
    return '';
}

sub bitmap {
    return undef,
}

sub list {
    my $self = shift;

}

1