package Moose::Meta::Method::Accessor::Native::Array::clear;
$Moose::Meta::Method::Accessor::Native::Array::clear::VERSION = '2.1213';
use strict;
use warnings;

use Moose::Role;

with 'Moose::Meta::Method::Accessor::Native::Array::Writer';

sub _maximum_arguments { 0 }

sub _adds_members { 0 }

sub _potential_value { '[]' }

sub _inline_optimized_set_new_value {
    my $self = shift;
    my ($inv, $new, $slot_access) = @_;

    return $slot_access . ' = [];';
}

sub _return_value { '' }

no Moose::Role;

1;
