package Moose::Exception::CannotDelegateWithoutIsa;
$Moose::Exception::CannotDelegateWithoutIsa::VERSION = '2.1213';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Attribute';

sub _build_message {
    "Cannot delegate methods based on a Regexp without a type constraint (isa)";
}

1;
