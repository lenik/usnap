
#
#
# Request/Response language
#
#	- Authority-based language
#	- Security program
#	- Pure algorithm script
#	- Trustee manager
#	- ...
#




# samples:


# 1, pure algorithm: m + m+1 + m+2 + +... + n-1 + n

	retrieve([BASIC KEY], k);
	takeoff([BASIC KEY], k);

	basic_operator: BO;

	basic.int m;
	basic.int n;
	basic.int i;
	basic.int total;

	retrieve([PROGRAM CONTROL KEY], kPC);
	takeoff([PROGRAM CONTROL KEY], kPC);

	program_control_operator: PCO;

	BO.= total, 0;

	PCO.for i=m:n {
		BO.= total, BO.+(total, i)
	}

# 2, bank load/save moeny

	retrieve([FUNCTIONAL KEY], kF);
	takeoff([FUNCTIONAL KEY], kF);

	...
