package Moose::Exception::CannotInlineTypeConstraintCheck;
$Moose::Exception::CannotInlineTypeConstraintCheck::VERSION = '2.1213';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

sub _build_message {
    my $self = shift;
    'Cannot inline a type constraint check for ' . $self->type_name;
}

1;
