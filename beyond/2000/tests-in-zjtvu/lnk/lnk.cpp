// lnk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windowsx.h>
#include <objbase.h>
#include <shlobj.h>
#include <stdio.h>
#include <initguid.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>


int main(int ac, char *av[])
    {
    if (ac != 2)
        {
        printf("Syntax: ln <pathname>\n");
        return 0;
        }

    IShellLink *psl;                            // pointer to IShellLink i/f
    HRESULT hres;
    WIN32_FIND_DATA wfd;
    char szGotPath[MAX_PATH];

    // Get pointer to the IShellLink interface.

    hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
                                IID_IShellLink, (LPVOID *)&psl);

    if (SUCCEEDED(hres))
        {
        // Get pointer to the IPersistFile interface.

        IPersistFile *ppf;
        hres = psl->QueryInterface(IID_IPersistFile, (LPVOID *)&ppf);

        if (SUCCEEDED(hres))
            {
            WORD wsz[MAX_PATH];

            // Ensure string is Unicode.
            MultiByteToWideChar(CP_ACP, 0, av[1], -1, wsz, MAX_PATH);

            // Load the shell link
            hres = ppf->Load(wsz, STGM_READ);
            if (SUCCEEDED(hres))
                {
                // Resolve the link.

                hres = psl->Resolve(0, SLR_ANY_MATCH);
                //                  ^
                // Using 0 instead -| of hWnd, as hWnd is only used if
                // interface needs to prompt for more information. Should use
                // hWnd from current console in the long run.

                if (SUCCEEDED(hres))
                    {
                    strcpy(szGotPath, av[1]);

                    hres = psl->GetPath(szGotPath, MAX_PATH,
                                (WIN32_FIND_DATA *)&wfd, SLGP_SHORTPATH );
                    if (!SUCCEEDED(hres))
                        printf("GetPath failed!\n");

                    printf("This points to %s\n", wfd.cFileName);
                    if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                        printf("This is a directory\n");
                    }
                }
            else
                printf("IPersistFile Load Error\n");
            ppf->Release();
            }
        else
            printf("QueryInterface Error\n");
        psl->Release();
        }
    else
        printf("CoCreateInstance Error - hres = %08x\n", hres);
    return 0;
    }
