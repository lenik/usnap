EPFS 数学

Pretty Expression 表达式语法


sum(i=0;i<100;i++)(expression)

pretty{
	a+bc	# !exist(bc) && exist(b) && exist(c) |- a + b * c

	sum(i=0;100)
	sum(i+j+k=100)
	sum(i is Z && 0<i<10)
	a<x<b ==> a <x && x < b

}
