

#
#
# Think-In-Time Implementation
#   - Memory layout
#
#


# samples


# -

	- 1

	bit
	B:8
	B:16
	B:32
	B:64


	byte
		bit(8)

		// byte opt&specific

	_signed:
		msb	sign:1

	_little_signed:
		lsb	sign:1


	i8 B:8 _signed
	i16 B:16 _signed

	float(nsign,nbase,nexp)
		msb	sign:nsign
		msb	base:nbase
		msb	exp:nexp

	typedef float(1,10,5) _IEEE_1234_float
	typedef _IEEE_1234_float float:16

	_SIMD_BYTE_4S
		msb	B1
		msb	B2
		msb	B3
		msb	B4

	typedef _SIMD_BYTE_4S	BS4


# ���� titi �������һ�����֣���һ����ͬ�����ڽṹ���壬�����˽ṹ�ڻ����еĴ�������
  ͬʱҲ����ʹ�ø߼������������������� primary ���Ͳ���Ҫ���ָ߼�������
  ���ڴ洢���ֶ��ԣ����ܻ���Ҫ�߼��������������������Էŵ� tit ģ�͵�һ����ͼ���н��С�

  ��ʵ�ϣ�HAS ���кܶ�ط��� COM �ӿڷ�ʽ����ȷ�е�˵ COM �ӿڷ�ʽ��HAS ������
  ֻ���� COM �ӿ�ֻ�����ڶ����������

	[ using _x86_assemble ]
	byte
		+	add
		-	sub
	int
		+	ADC
		-	sbb






# primary ������������֧��

	- �� has �ֲ�
	- ������֧�ֲ�
		- titi-primary bit �� titi �ڲ�֧�ֵ�����Ҫ������, ����
			[ and �� not ]
		- һ��λ
			or = not (not a and not b)
			xor = (a and not b) or (not a and b)
			imp = not a or b
		- shift
			shift(B0, B1, ..., Bn-1, shiftn)
		- rotate shift
		- ����
		- ɢ��
		-
	- ����֧�ֲ�
		- �� �� �� �� ��������
		- ����
		-
	- ʵ��֧�ֲ�
	-

# �ø�����ʽ��ʾ byte

	����λ��
		- �� (a, b)
		-
	x86 ����
		- ��
			if (���ؼĴ���c ���Ա���ֵ, ��֧�ּӷ�)
				mov c, a
				mov c, b
			else if (��ȡ��ʱ�Ĵ���: T1	֧�ּӷ�, ��ֵ)
				mov T1, a
				add T1, b
				mov c, T1
			else
				�����У���ͼ����
		-
	x86 ��������

	C ���Բ�
		- ��
			inline {
				return (BYTE)a + (BYTE)b;
			}

	...
