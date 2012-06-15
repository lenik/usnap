
#include "Mfc1_Interface.h"

class CMfc1_Imp1 : public CCmdTarget {
public:
	CMfc1_Imp1();
	virtual ~CMfc1_Imp1();

public:
	BEGIN_INTERFACE_PART(CMfc1_Interface1_Imp1, IMfc1_Interface1)
		STDMETHOD(I1_Method1)();
	END_INTERFACE_PART(CMfc1_Interface1_Imp1)

	BEGIN_INTERFACE_PART(CMfc1_Interface2_Imp1, IMfc1_Interface2)
		STDMETHOD(I2_Method1)();
	END_INTERFACE_PART(CMfc1_Interface2_Imp1)

	DECLARE_INTERFACE_MAP();
	DECLARE_OLECREATE(CMfc1_Imp1);
	DECLARE_DYNCREATE(CMfc1_Imp1);
};

typedef CMfc1_Imp1
	*PMFC1_IMP1,
	*LPMFC1_IMP1;
