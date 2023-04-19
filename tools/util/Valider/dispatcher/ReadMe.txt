
示例
		dispatcher x:\abc\temp x:\maindir /s

		其中第201个复制有 x:\abc\temp --> x:\maindir\sub\s2\temp

%%	%
%r	相对于目标的路径	..\..\..\abc
%R	相对与源的路径		..\maindir\sub\s2

%s	源文件基名字		temp
%d	目标目录		x:\maindir\sub\s2
%D	目标文件名		x:\maindir\sub\s2\temp
%c	计数器			201
%*	随机字节		?
%?	随机数字		(0-9)
