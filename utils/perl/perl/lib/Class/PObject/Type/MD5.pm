package Class::PObject::Type::MD5;

# MD5.pm,v 1.3 2003/09/09 00:11:59 sherzodr Exp

use strict;
#use diagnostics;
use vars ('$VERSION', '@ISA');
use Digest::MD5 ("md5_hex");
use Class::PObject::Type;
use overload (
    'eq'    => sub { $_[0]->id eq md5_hex($_[1]) },
    bool  => sub { $_[0]->id ? 1 : 0 },
    fallback => 1,
);

$VERSION = '1.00';
@ISA = ("Class::PObject::Type");

sub _init {
    my $self = shift;
    $self->id or return undef;
    $self->{id} = md5_hex($self->id)
}

1;
__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

Class::PObject::Type::MD5 - Defines MD5 column type

=head1 DESCRIPTION

ISA L<Class::PObject::Type|Class::PObject::Type>

=head1 COPYRIGHT AND LICENSE

For author and copyright information refer to Class::PObject's L<online manual|Class::PObject>.

=cut
