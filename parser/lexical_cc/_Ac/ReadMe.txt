

	Automation Compiler 1b.0

	使用不同实现方法的第一版自动机语言编译器

	抽象加强

		1、跳转加强
		2、嵌入代码加强 (伪指令加强)
		//3、动态状态(动态增加、改变)加强

跳转关键字

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



// 自动机函数的调用: 函数返回时输出一个返回值
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

// 先行表示

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
