

	�﷨�������ĵ�һ���汾


Gc���﷨��


	Gc��ҪLR(0)�͹�����?


SYMBOL:
	ÿ��symbol����Ӧһ��ID, ���ڹ�Լ����ͨ���ж�ID���ж��Ƿ���ȷsymbol,
	�����˲�ѯ��symbol���ȼ�ʱͨ��ӳ��ID->SYMBOL�ṹ���ȡ���ȼ���
	SYMBOL�����������й���symbol�Ĳ�����Ϣ��

G����ԭʼ�ű���

G_File<accept=nul>:
	_
	| G_Source	R@ {
	|_;

G_Source<accept=std::list<std::pair<symbol, symbols>>>:
	_
	| Production
	| G_Source Production
	|_;

Production<accept=std::pair<symbol,symbols>>:
	_
	| PLeft ':' PRight ';'
	|_;

PLeft<accept=symbol>:
	_
	| Symbol
	| Symbol '<' SymbolParam '>'
	|_;

PRight<accept=symbols>:
	_
	| Symbol
	| PRight '|' Symbol
	|_;

SymbolParam<accept=nul>:
	_
	| ParamPair
	| SymbolParam ',' ParamPair
	|_;

ParamPair<accept=std::pair<string,var>>:
	_
	| ParamName '=' ParamVal
	|_;

ParamName<accept=string>:
	_
	| ID
	|_;

ParamVal<accept=var>:
	_
	| Expression
	|_;

Symbol<accept=string>:
	_
	| ID	R@ { Symbol = ID; }
	|_;

------------------------

exp<int>:
	_
	| num				R@ { exp = num; }
	| exp<id=e1> '+' exp<id=e2>	R@ { exp = e1 + e2; }
	| exp<id=e1> '-' exp<id=e2>	R@ { exp = e1 - e2; }
	|_;
