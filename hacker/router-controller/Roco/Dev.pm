package Roco::Dev;

use strict;
use Exporter;
use vars qw/@ISA @EXPORT/;

@ISA    = qw(Exporter);
@EXPORT = qw();

sub new {
    my ($class, $addr) = @_;
    my $self;
    bless \$self, $class;
    $self->assoc($addr) if defined $addr;
}

sub assoc {
    my ($self, $addr) = @_;
    $self->{ADDR} = $addr;
}

sub serv {
    my ($self, $name, $args) = @_;
    my @args = qsplit(qr/\s+/, $args);
    $self->SERV($name, @args);
}

sub features {
    my $self = shift;
    my $all;
    while (defined $self) {
        my $one = $self->FEATURE;
        $all->{$_} = $one->{$_} for keys %$one;
        $self = $self->SUPER;
    }
    return $all;
}

sub SERV {

}

sub FEATURE {

}

1;
