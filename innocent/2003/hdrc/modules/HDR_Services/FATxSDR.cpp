
#include "FATxSDR.h"


enum SectorType {
    stoUnknown = 0,
    stoBoot,
    stoFSI,
    stoFAT,
    stoDirectory,
    stoBad,
};

enum ClusterType {
    ctoUnknown,
    ctoFree,
    ctoDirectory,
    ctoFile,
    ctoStream,
    ctoSystem,
};




SectorType DetectSectorType(LPBYTE pSectorData) {
    ASSERT(pSectorData);

}

ClusterType DetectClusterType(FATx *pFS, DWORD cluster) {
    ASSERT(pFS);
    if (cluster < 2) return ctoSystem;

}
