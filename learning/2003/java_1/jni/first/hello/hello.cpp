// hello.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include <jni.h>
#include <stdio.h>
#include "HelloClient.h"



BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}


extern "C"
JNIEXPORT void JNICALL Java_HelloClient_ShowMessage(JNIEnv *env, jobject _this, jstring jMsg) {
    const char *msg = env->GetStringUTFChars(jMsg, 0);

    printf("[JNI Server]: %s\n", msg);

    env->ReleaseStringUTFChars(jMsg, msg);
}
