

〉递归函数类型定义
	no nest typedef was acceptable as:
		typedef int (*talkproc)(char *words, talkproc target);
	so were:
		typedef int (*talkproc1)(char *words, talkproc2 target);
		typedef int (*talkproc2)(char *words, talkproc1 target);
	and etc.

	but can:
		typedef int (*talkproc)(char *words, void *target_proc);


〉名字太长的解决方法 (C4786)

	MSDN中提供的方法是 要么将模版类名字缩短，要么将模版参数类名字缩短。
	都没有彻底解决这个问题。

	#pragma warn(disable:c4786)
	干脆。

> typedef是可以继承的。也可以在派生类中改变。

>
