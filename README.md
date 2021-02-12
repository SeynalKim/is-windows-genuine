# is-windows-genuine
Written in C++, a simple function that checks if Windows License is Genuine. Tested and working on Vista, Windows 7, Windows 8, and Windows 10.

# Example of usage

Include the following library on your class.
```
/*Include the following library*/
#define _WIN32_WINNT 0x600
#include <iostream>
#include <windows.h>
#include <slpublic.h>
#include <tchar.h>
#pragma comment(lib, "Slwga.lib")
#pragma comment(lib, "Rpcrt4.lib")
``` 

Create the below function.
```
bool isGenuineWindows(){
    GUID uid;
    RPC_WSTR rpc = (RPC_WSTR)_T("55c92734-d682-4d71-983e-d6ec3f16059f"); /* WindowsAppId */
    UuidFromString(rpc, &uid);
    SL_GENUINE_STATE state;
    SLIsGenuineLocal(&uid, &state, NULL);
    return state == SL_GEN_STATE_IS_GENUINE;
}
```

Call `isGenuineWindows()` to check for licensing status of Windows, for example.
```
if (isGenuineWindows()) {
  cout << "Genuine Licensed" << endl;
}else {
  cout << "NOT Genuine" << endl;
}
```

