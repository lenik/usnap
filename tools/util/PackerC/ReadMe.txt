
�����������ɰ�װ������������
----------------------------------------------------------------
Packer C

	�����������	Packer Studio
	���������	Packer Compiler


�ƻ�����

	1����� PDS ��������ű�
	2������ļ��淶
	3��PC�����䷽��


1���������ű� Packer Description Script (working)
	PDS/0 �����淶
	PDS/1 ԭʼ��������
	PDS/2 ����������չ		���������͵Ľ��ͼ���ȡ
	PDS/3 �������� �����任		��ʽת��
	PDS/4 ���ݱ��� ������		��Ч���ѹ���ɼ���ȫ��
	PDS/5 �����չ			���͵�ý���Լ���չ
	PDS/6 ǰ����չ			�û����ý�����ƹ���


	PDS/0 �����淶
		�ṹʽ����

	PDS/1
		* ԭʼ�������ͺͽṹ��
		* ��������:xtype
			# xtype file;
			# xtype registry;
		* ���ݶ���
			* �ű�����
				int x = 3, y = 4;
				file f1 = file::open(...);
			* �������
				int://3;
				int://4;
				file://d:\data\abc.dat;
	PDS/2 ����������չ(I/O)
		* ���������͵�ʵ��������DLL::API
			xtype file(setupass.dll::FileApi)
		* �ڽű���ʵ��
			xtype file {
				string filename;
				in {
					long hf = file::open(filename);
					read(hf, buf);
				}
				out {
					long hf = file::open(filename);
					write(hf, buf);
				}
			}
	PDS/3 ��������
		PDS/3A �������� ��/��
		PDS/3B �������� ��/��
	PDS/4 ���ݱ���
		PDS/4A ���ݱ���
		PDS/4B ���ݽ���
	PDS/5 �����չ

	PDS/6 ǰ����չ


2������ļ��淶

	* �������
	* ��������ӿ�
