







# �ַ�����ʽ��������ʽ (����ڶ�����)
string_regular:


# ���
regular:
	range_spec
	escape_char
	display_char
	repeat_spec
	find_strategy
	selection_spec
	look_ahead_spec
	context_spec



# ʵ��
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

���裬̰��

....|...	ǰ�� look-ahead

..(...)...	ѡ��
