if (! -e "C:\\Program Files (x86)\\Microsoft Visual Studio\\Installer\\vswhere.exe")
{
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

	print $ENV{"VS" . $found . "COMNTOOLS"} . "\\..\\..\\VC\\";
}
else
{
	$found = `"C:\\Program Files (x86)\\Microsoft Visual Studio\\Installer\\vswhere.exe" -latest -property installationPath`;
	$found =~ s/[\r\n]+$//;
	print $found . "\\VC\\Auxiliary\\Build\\";
}
