
#pragma once

namespace EventByrefLib {
	struct _declspec(uuid("00000000-4341-FFB0-0004-486954656368"))
		Libid;
};

class EBSink1 :
	//public CComObjectRoot,
	public IDispEventImpl</*nID*/1, EBSink1,
		&__uuidof(EventByrefLib::ICaEventByrefEvents),
		&__uuidof(EventByrefLib::Libid)
		> {
public:

	EBSink1();
	~EBSink1();

public:
	EventByrefLib::ICaEventByrefPtr m_eb1;

public:
	void _stdcall onEventTest() {
		_CT("onEventTest");
	}
	void _stdcall onEvent1() {
		_CT("onEvent1");
	}
	void _stdcall onEvent2() {
		_CT("onEvent2");
	}

	BEGIN_SINK_MAP(EBSink1)
		SINK_ENTRY_EX(/*nID*/1,
			__uuidof(EventByrefLib::ICaEventByrefEvents),
			/*dispid*/1, onEventTest)
		SINK_ENTRY_EX(/*nID*/1,
			__uuidof(EventByrefLib::ICaEventByrefEvents),
			/*dispid*/2, onEvent1)
		SINK_ENTRY_EX(/*nID*/1,
			__uuidof(EventByrefLib::ICaEventByrefEvents),
			/*dispid*/3, onEvent2)
	END_SINK_MAP()

public:
	void connect();
	void disconnect();

};
