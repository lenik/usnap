

template<class UNITTYPE>
class splitBox {
	struct SPLITBOX {
		UNITTYPE w, h;
	};
	typedef CList<UNITTYPE, UNITTYPE> UNITLIST;
	typedef CList<SPLITBOX, SPLITBOX> BOXLIST;

protected:
	UNITLIST	sepXs;
	UNITLIST	sepYs;

	BOXLIST		sepBoxs;

	BOOL		InsertSepX(UNITTYPE sx);
	BOOL		InsertSepY(UNITTYPE sy);
	BOOL		DeleteSepX(UINT index);
	BOOL		DeleteSepY(UINT index);

public:
	;
};

template<class UNITTYPE>
BOOL splitBox::InsertSepX(UINTTYPE sx) {
	// 插入纵向分割线
