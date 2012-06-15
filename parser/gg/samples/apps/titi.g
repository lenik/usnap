

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


# 描述 titi 定义的另一个部分，这一部分同样属于结构定义，描述了结构在机器中的处理方法。
  同时也可以使用高级语言来描述。但对于 primary 类型不需要这种高级描述。
  对于存储布局而言，可能会需要高级描述，但这种描述可以放到 tit 模型的一个视图层中进行。

  事实上，HAS 层有很多地方与 COM 接口方式相像，确切的说 COM 接口方式与HAS 层相像，
  只不过 COM 接口只能用于二进制组件。

	[ using _x86_assemble ]
	byte
		+	add
		-	sub
	int
		+	ADC
		-	sbb






# primary 数据类型运算支持

	- 用 has 分层
	- 二进制支持层
		- titi-primary bit 是 titi 内部支持的最重要的类型, 它有
			[ and 和 not ]
		- 一个位
			or = not (not a and not b)
			xor = (a and not b) or (not a and b)
			imp = not a or b
		- shift
			shift(B0, B1, ..., Bn-1, shiftn)
		- rotate shift
		- 逆向
		- 散射
		-
	- 整数支持层
		- 加 减 乘 除 带余数除
		- 饱和
		-
	- 实数支持层
	-

# 用各种形式表示 byte

	基础位层
		- 加 (a, b)
		-
	x86 汇编层
		- 加
			if (返回寄存器c 可以被赋值, 且支持加法)
				mov c, a
				mov c, b
			else if (获取临时寄存器: T1	支持加法, 赋值)
				mov T1, a
				add T1, b
				mov c, T1
			else
				不可行，试图重试
		-
	x86 保护汇编层

	C 语言层
		- 加
			inline {
				return (BYTE)a + (BYTE)b;
			}

	...
