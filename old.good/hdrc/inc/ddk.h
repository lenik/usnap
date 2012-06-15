
#pragma once

#include <pos/error.h>
using namespace pos::ab;


struct DriveInfo {
    char *      DevicePath;
    char *      Label;
};


Err GetDrives() {
    HDEVINFO hDevInfo;
    Err err;

    hDevInfo = ::SetupDiGetClassDevs(
        NULL,       // Ignored when Flags & All classes
        NULL,       // No filter string
        NULL,       // HWND
        DIGCF_ALLCLASSES
        );

    err.bFailure = true;
    if (hDevInfo == INVALID_HANDLE_VALUE) return err;
}
