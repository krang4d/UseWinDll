#include <iostream>
//#include "mega2lib.h"
#include <windows.h>
#include "lib/imegalib.h"

using namespace std;



imegalib *getMegaLibInstance();

int main()
{
    imegalib *pmegalib = getMegaLibInstance();
    if(!pmegalib) return 1;
    pmegalib->sayHello();
    pmegalib->destroy();
    return 0;
}

imegalib *getMegaLibInstance()
{
    //Load the DLL
    HINSTANCE dll_handle = ::LoadLibrary(TEXT("libmega2lib.dll"));
    if (!dll_handle) {
        cerr << "Unable to load DLL!\n";
        return nullptr;
    }
    cout << "libmega2lib.dll is loaded\n" << endl;

    // A factory of IKlass-implementing objects looks thus
    // typedef imegalib* (__cdecl *iklass_factory)();
    // Get the function from the DLL
    iklass_factory factory_func = reinterpret_cast<iklass_factory>(
        ::GetProcAddress(dll_handle, "create_klass"));
    if (!factory_func) {
        cerr << "Unable to load create_klass from DLL!\n";
        ::FreeLibrary(dll_handle);
        return nullptr;
    }
    cout << "get create_klass() from DLL!\n" << endl;

    // Ask the factory for a new object implementing the IKlass
    // interface
    return factory_func();
}
