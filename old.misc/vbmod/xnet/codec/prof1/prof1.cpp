// prof1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace XnetCodec;

HRESULT addmem(IInputBufferPtr ptr, void *p, int n = -1) {
    HRESULT hr;
    if (n == -1)
        n = strlen((const char *)p);
    SAFEARRAY *sa = SafeArrayCreateVector(VT_I1, 0, n);
    memcpy(sa->pvData, p, n);
    hr = ptr->AddBytes(&sa);
    SafeArrayDestroy(sa);
    return hr;
}

// TODO  pointer by raw. not thru COM.
//       to get more precise result.
void mod1() {
    HRESULT hr;
    IInputBufferPtr ibuf;
    ibuf.CreateInstance(__uuidof(InputBuffer));

    hr = addmem(ibuf, "Xmsg 12 \"What\\\"ever\" \"Hello, World!\" Last;\n");
    hr = addmem(ibuf, "Ynew 345 \"What\\\"ever\" \"Hello, World!\" Last;\n");

    int i = 0;
    while (ibuf->StatementReady()) {
        i++;
        IStatementPtr st = ibuf->GetStatement();
        SAFEARRAY *sa = st->Encode();

        int cb = sa->rgsabound[0].cElements;
        // memcpy(printbytes, sa->pvData, cb);
        // print..

        hr = SafeArrayDestroy(sa);
    }
}

int main(int argc, char* argv[])
{

    CoInitialize(NULL);

    for (int t = 0; t < 100000; t++) {
        mod1();
        printf(".");
    }

    return 0;
}
