// jobject.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include <jni.h>
#include <stdio.h>
#include "UseObjects.h"

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}


extern "C"
JNIEXPORT void JNICALL Java_UseObjects_changeObject(JNIEnv *env, jobject _this, jobject obj) {
    jclass cls = env->GetObjectClass(obj);
    jfieldID fid = env->GetFieldID(cls, "aValue", "I");
    jmethodID mid = env->GetMethodID(cls, "divByTwo", "()V");

    int value = env->GetIntField(obj, fid);
    printf("[Native] aValue = %d\n", value);

    env->SetIntField(obj, fid, 6);
    env->CallVoidMethod(obj, mid);

    value = env->GetIntField(obj, fid);
    printf("[Native] aValue = %d\n", value);


}
