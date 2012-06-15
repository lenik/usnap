







# 字符串形式的正则表达式 (相对于二进制)
string_regular:


# 框架
regular:
	range_spec
	escape_char
	display_char
	repeat_spec
	find_strategy
	selection_spec
	look_ahead_spec
	context_spec



# 实现
regular:
	'/' regular_exp '/'

range_spec:
	'[' opt_not_range range_segments ']'

opt_not_range:
	| '^'
	;

range_segments:
	range_segment
	| range_segments range_segment
	;

range_segment:
	rss_single_char
	rss_from_to_chars

rss_single_char:
	rss_display_char
	rss_escape_char

rss_display_char
rss_escape_char
	"\\n"
	"\\r"
	"\\\\"

rss_from_to_chars:
	rss_single_char '-' rss_single_char
	;

escape_char:
	"\\n"

display_char:

repeat_spec:
	'?'
	| '*'
	| '+'
	| '{' NUMBER '}'
	;

find_strategy:
	"<lazy>"
	"<avid>"

context_spec:
	'^'
	| '$'
	| "<preceded with>"
	| "<followed by>"

[ range-spec ]

\escape

.	any char

^ $	line-begin, line-end

? * + {}	0<<1, >=0, >0, spec

懒惰，贪婪

....|...	前看 look-ahead

..(...)...	选中
