

	语法编译器的第一个版本


Gc的语法：


	Gc需要LR(0)就够了吗?


SYMBOL:
	每个symbol都对应一个ID, 对于规约机制通过判断ID来判断是否正确symbol,
	而到了查询该symbol优先级时通过映射ID->SYMBOL结构体获取优先级。
	SYMBOL还有其它所有关于symbol的参数信息。

G语言原始脚本：

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
