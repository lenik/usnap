

#
#
# Think-In-Time
#   - Templated Information Technology
#   - Talk In Template
#
#





# hints

	- ����̳�Ҫ�������������Ŀɿ�ת��������Ӧ�����ƻ�����������ת����Ŭ����

	- ģ�� T ����ʵ���� T<x> ��һ�ֶ� T �򵥵ĺ��滻����ʹ����ģ�� T ������ʵ��
	  T<x> ������ T<...> �����ݡ�

	- ���������У���ص���֮���ת��������û�н�����ִ�Ľ�������������Զ��
	  ���������Դ���ת����ͼ��

	- POS(Practice-oriented structure)Ӧ���ܹ��Ϻõ�ת���� tit ģ���С�

	- Tit �����㷨���֣�Titi ����ṹʵ�ֲ��֡�
	  Titi ֧�ִ洢����(һ�ֱ�struct/union�����Ķ�Ľ������)��
	  Titi �ܹ�Ϊ Tit �ṩ�Ż����������ֵ���Ҳ���Ծ��� has �����󵽴

	- Tit ��Ϊģ��ģ�ͣ����ձ� Titi ʵ������


# sample instances

# 1, point, line, rect, box
#

	type coordinate;
	type point {
		coordinate x;
		coordinate y;
	};
	type line {
		point lt;
		point rb;
	};
	type rect {
		point lt;
		point rb;
	};
	type box {
		point lt;
		point rb;
		point isolated;
	};
