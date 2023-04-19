

#
#
# Think-In-Time
#   - Templated Information Technology
#   - Talk In Template
#
#





# hints

	- 对象继承要求派生类向基类的可靠转换，但不应该限制基类向派生类转换的努力。

	- 模版 T 类型实例化 T<x> 是一种对 T 简单的宏替换。这使得类模版 T 的类型实例
	  T<x> 与其它 T<...> 不兼容。

	- 在类型网中，相关的类之间的转换问题仍没有解决。现存的解决方案离理想很远。
	  类型网可以存在转换流图。

	- POS(Practice-oriented structure)应该能够较好的转换到 tit 模型中。

	- Tit 负责算法部分，Titi 负责结构实现部分。
	  Titi 支持存储布局(一种比struct/union高明的多的解决方案)。
	  Titi 能够为 Tit 提供优化导引。这种导引也可以经由 has 分析后到达。

	- Tit 作为模版模型，最终被 Titi 实例化。


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
