

#pragma once



template<typename _Ty>
struct XRange {
    // B-tree?

};

template<typename _Ty>
class XRangeDiscover {
public:
    _Ty     m_FuseDistance;             // posB - posA <= fuse distance, then fused.

    BOOL    m_bPreciseCHS;              // use precise C/H/S distance algorithm.

    enum MarkType {
        mtUnknown = 0,
        mtGood,
        mtBad
    };

    typedef MarkType XProc(const _Ty Pos);
    XProc   m_procX;

    BOOL    Scan(const _Ty PosA, const _Ty PosB);
};




template<typename _Ty>
BOOL Scan_Normal(_Ty PosA, _Ty PosB, BOOL bRelative) {
    ASSERT(PosA < PosB);

    MarkType mt;
    for (_Ty l = PosA; l <= PosB; l++) {
        mt = ScanUnit(l);
        ASSERT(mt != mtUnknown);

        if (mt == mtBad) {
            _Ty k = 1;
            while (PosA + k <= PosB) {
                mt = ScanUnit(PosA + k);
                if (mt == mtGood) {
                } else {
                }
                k += k;
            }
        }
    }


}






template<typename _Ty>
_Ty CHSDistance(const _Ty PosA, const _Ty PosB) {
    /*
    hard disk parameter:

        - Size: 3.5" or 5.25"
        - Real CHS or
    */

template<typename _Ty>
struct CHSDist {
    _Ty     cylinders;
    _Ty     heads;
    _Ty     sectors;
    int     interleave;
    BOOL    var_density;
    BOOL    special_platter;
    BOOL    upside_down;
    double  platter_size;

    _Ty     distance(_Ty C1, _Ty H1, _Ty S1, _Ty C2, _Ty H2, _Ty S2) {
        // using interleave
        if (interleave > 1) {
            // suppose (interleave,sectors) to be relatively primes
            S1 = ((interleave * (S1 - 1)) % sectors) + 1;
            S2 = ((interleave * (S2 - 1)) % sectors) + 1;
        }

        if (special_platter) {
            // ignore
        }
        if (var_density) {
            //
        }
    }
};
