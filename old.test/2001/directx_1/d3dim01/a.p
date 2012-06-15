
#!/usr/bin/perl

undef $/;

open(AA, "d") || die "errored";
$a=<AA>;
$a =~ s|/\*(.*)\*/||gm;
print $a;
close AA;
