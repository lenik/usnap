# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl Datatype.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use lib '..';
use Test::More tests => 25;
BEGIN { use_ok('Roco::Misc') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

use cmt::util;
use Data::Dumper;

my @which;
ok @which = which_package('cmt::path'), 'which_package';
# diag Dumper(\@which);

ok @which = which_package('Net::'), 'which_package';
# diag Dumper(\@which);

is which_package('Roco::DevDB::'), '../Roco/DevDB', 'parent-only';

is make_id('My name is Lenik!'), 'My_name_is_Lenik_', 'make-id';

SKIP: {
    if (1) {
        skip 'local test', 1;
    } elsif (-f 'c:/__Q_50__') {
        is probe_webdev('192.168.1.254:8080'), 'TP-LINK Router R480T', 'q/office';
    } elsif (-f 'c:/__FRONT_80_C73') {
        is probe_webdev('192.168.2.254:80'), 'TP-LINK Wireless Router WR340G', 'q/home';
    } else {
        skip 'local test', 1;
    }
}

# diag Dumper(loadmodels);
ok loadmodels, 'loadmodels';

my ($model, $equ);
($model, $equ) = getmodel('TP-LINK Wireless Router WR340G');
is $model->{Name}, 'TP-LINK Router (General)', 'getmodel-1';
is $equ, 1, 'getmodel-2';

($model, $equ) = getmodel('TP-LINK [Wireless] Router WR340G-NewVer');
is $model->{Name}, 'TP-LINK Router (General)', 'getmodel-1';
is $equ, 0, 'getmodel-2';

my $actions = $model->{Features}->{'wan.connect'};
is interp_params($model, $actions->[0]),
   '/userRpm/StatusRpm.htm?Connect=1&wan=1', 'interp_params default';
is interp_params($model, $actions->[0], wanport=>2),
   '/userRpm/StatusRpm.htm?Connect=1&wan=2', 'interp_params overriden';

set_locale 'en';
ok loadres, 'loadres';
is L('roco.title'), 'Roco - Router Controller', 'L-1';

my @lst = (1, 2, 2, 3, 4, 4, 4, 6, 11);
diag join(' ', @lst);
my @tst = 0..9;
for (@tst) {
    my $i = bsearch undef, $_, @lst;
    # diag "find $_ -> $i: ".join(' ', @lst[$i..$#lst]);
    ok $_ <= $lst[$i], "bsearch $_ -> $i";
}
