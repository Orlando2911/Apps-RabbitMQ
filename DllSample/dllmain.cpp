// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


extern "C" _declspec(dllexport) int Analysis(unsigned short* imageData, int imageDataSize, int imageWidth, bool& result)
{
    result = ((imageData[0] + imageData[5]) % 2); // Just as a quick example.
    return 0; // no error
}