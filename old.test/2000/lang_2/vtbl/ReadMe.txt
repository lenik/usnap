

重定向虚函数地址
---------------------------

1, _thiscall 协议

	_thiscall 可以和 _cdecl/_stdcall 结合使用，以定制参数析构方案。

	在进入 _thiscall 过程前， ECX含有实例指针。
