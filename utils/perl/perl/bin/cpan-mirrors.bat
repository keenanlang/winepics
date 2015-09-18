@rem = '--*-Perl-*--
@echo off
if "%OS%" == "Windows_NT" goto WinNT
IF EXIST "%~dp0perl.exe" (
"%~dp0perl.exe" -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
) ELSE IF EXIST "%~dp0..\..\bin\perl.exe" (
"%~dp0..\..\bin\perl.exe" -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
) ELSE (
perl -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
)

goto endofperl
:WinNT
IF EXIST "%~dp0perl.exe" (
"%~dp0perl.exe" -x -S %0 %*
) ELSE IF EXIST "%~dp0..\..\bin\perl.exe" (
"%~dp0..\..\bin\perl.exe" -x -S %0 %*
) ELSE (
perl -x -S %0 %*
)

if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" goto endofperl
if %errorlevel% == 9009 echo You do not have Perl in your PATH.
if errorlevel 1 goto script_failed_so_exit_with_non_zero_val 2>nul
goto endofperl
@rem ';
#!/usr/bin/perl
#line 29

use strict;
use warnings;

use CPAN::Mirrors;
use Data::Dumper;

my $mirrored_by_file = '/Users/brian/.cpan/sources/MIRRORED.BY';
my $mirrors = CPAN::Mirrors->new( $mirrored_by_file );

my $seen = {};
my $n = 5;

my $best_continent = $mirrors->find_best_continents( n => $n, seen => $seen, verbose => 1 );
print "Best continent is $best_continent\n";

my @mirrors = $mirrors->get_mirrors_by_continents( $best_continent );

my $callback = sub { 
	my( $m ) = @_; 
	printf "%s = %s ms\n", $m->hostname, 1000 * $m->rtt
	};
my @sorted_mirrors = $mirrors->get_mirrors_timings( \@mirrors, $seen, $callback );

print "Best mirrors are ",
	join ' ', map( $_->hostname, @sorted_mirrors[0..$n-1] ),
	"\n";

print "Best urls are\n\t",
	join( "\n\t", map( $_->http, @sorted_mirrors[0..$n-1] ) ),
	"\n";

__END__
:endofperl
