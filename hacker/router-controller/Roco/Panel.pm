package Roco::Panel;

use strict;
use vars qw/@ISA/;

our $opt_verbtitle      = __PACKAGE__;
our $opt_verbtime       = 0;
our $opt_verbose        = 1;

@ISA    = qw();

sub new {
    my $class = shift;
    my $self = bless {}, $class;
    $self->init(@_);
    return $self;
}

sub init {
}

sub want_scroll {
    0
}

sub create {
    my ($self, $frame) = @_;
}

sub remove {
}

1