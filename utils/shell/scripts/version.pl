$found = 0;

foreach (sort keys %ENV)
{
	if ($_ =~ /^VS([0-9]+)COMNTOOLS/)
	{
		if ($1 > $found)
		{
			$found = $1;
		}
	}
}

print $ENV{"VS" . $found . "COMNTOOLS"};