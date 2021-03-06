package MooseX::Declare::Syntax::MethodDeclaration::Parameterized;
$MooseX::Declare::Syntax::MethodDeclaration::Parameterized::VERSION = '0.39';
use Moose::Role;
use MooseX::Role::Parameterized 0.12 ();
use namespace::autoclean;

around register_method_declaration => sub {
    my ($next, $self, $parameterizable_meta, $name, $method) = @_;
    my $meta = $self->metaclass_for_method_application($parameterizable_meta, $name, $method);
    $self->$next($meta, $name, $method);
};

sub metaclass_for_method_application {
    return MooseX::Role::Parameterized->current_metaclass;
}

1;
