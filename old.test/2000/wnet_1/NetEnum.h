
#include <winnetwk.h>

typedef void (_stdcall * WNETENUMPROC)(LPNETRESOURCE element);

DWORD _stdcall WNet_enum(LPNETRESOURCE nr_contain, WNETENUMPROC lpfnEnum);
LPTSTR _stdcall WNet_status(DWORD status);

