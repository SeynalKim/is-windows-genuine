#define _WIN32_WINNT 0x600
#include <iostream>
#include <windows.h>
#include <slpublic.h>
#include <tchar.h>
#pragma comment(lib, "Slwga.lib")
#pragma comment(lib, "Rpcrt4.lib")

using std::cout;
using std::endl;

bool isGenuineWindows()
{
    GUID uid;
    RPC_WSTR rpc = (RPC_WSTR)_T("55c92734-d682-4d71-983e-d6ec3f16059f"); /* WindowsAppId */
    UuidFromString(rpc, &uid);
    SL_GENUINE_STATE state;
    SLIsGenuineLocal(&uid, &state, NULL);
    return state == SL_GEN_STATE_IS_GENUINE;
}

int main()
{
    if (isGenuineWindows()) {
        cout << "Genuine Licensed" << endl;
    }
    else {
        cout << "NOT Genuine" << endl;
    }
    return 0;
}
