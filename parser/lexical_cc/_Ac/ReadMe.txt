

	Automation Compiler 1b.0

	ʹ�ò�ͬʵ�ַ����ĵ�һ���Զ������Ա�����

	�����ǿ

		1����ת��ǿ
		2��Ƕ������ǿ (αָ���ǿ)
		//3����̬״̬(��̬���ӡ��ı�)��ǿ

��ת�ؼ���

jumptype:
	stackops target
	;

stackops:
	stackop
	| stackops stackop
	;
stackop:
	'-'		{ add_eat_char }
	| '>'		{ }
	| '['		{ add_go_in_protect }
	| ']'		{ add_go_out_protect }
	| '}'		{ add_force_out_protect }
	| 'v'		{ add_save_state }
	| '^'		{ add_retstate }



// �Զ��������ĵ���: ��������ʱ���һ������ֵ
s:
	T: -v test_word |clearB_this_T_char ;
	verify: -> next ;
	error: -> next | c@c report();
			;
;
test_word:
	W: -^ verify ;
	~: -^ error ;
;

// ���б�ʾ

N = [0-9]

getnum:
	N|N: -> getnum |pad_N ;
	~: c@c if (N_length>0) {
			^ verify ;
	   c@c } else {
			^ error ;
	   c@c }
	   ;
;
