

���ݹ麯�����Ͷ���
	no nest typedef was acceptable as:
		typedef int (*talkproc)(char *words, talkproc target);
	so were:
		typedef int (*talkproc1)(char *words, talkproc2 target);
		typedef int (*talkproc2)(char *words, talkproc1 target);
	and etc.

	but can:
		typedef int (*talkproc)(char *words, void *target_proc);


������̫���Ľ������ (C4786)

	MSDN���ṩ�ķ����� Ҫô��ģ�����������̣�Ҫô��ģ��������������̡�
	��û�г��׽��������⡣

	#pragma warn(disable:c4786)
	�ɴࡣ

> typedef�ǿ��Լ̳еġ�Ҳ�������������иı䡣

>
