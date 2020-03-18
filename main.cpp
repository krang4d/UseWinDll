#include <iostream>
//#include "mega2lib.h"
#include <stdio.h>

#if defined (__GNUC__) && defined(__unix__)
    #include <dlfcn.h>
#elif defined (WIN32)
    #include <windows.h>
#endif

#include "CreateDll/imegalib.h"

//using namespace std;

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
#if defined (__GNUC__) && defined(__unix__)
    void    *handle;
    //int     *iptr, (*fptr)(int);

    /* open the needed object */
    handle = dlopen("/home/pgg/qt_projects/UseWinDll/CreateDll/libmega2.so", RTLD_LOCAL | RTLD_LAZY);

    /* find the address of function and data objects */
    iklass_factory factory_func = (iklass_factory)(dlsym(handle, "create_klass"));
    //iptr = (int *)dlsym(handle, "my_object");
    return factory_func();

    /* invoke function, passing value of integer as a parameter */
    //(*fptr)(*iptr);

#elif defined (WIN32)
    //Load the DLL
    HINSTANCE dll_handle = ::LoadLibrary(TEXT("libmega2lib.dll"));
    if (!dll_handle) {
        printf("Unable to load DLL!\n");
        return nullptr;
    }
    printf("libmega2lib.dll is loaded\n");

    // A factory of IKlass-implementing objects looks thus
    // typedef imegalib* (__cdecl *iklass_factory)();
    // Get the function from the DLL
    iklass_factory factory_func = (iklass_factory)(::GetProcAddress(dll_handle, "create_klass"));
    if (!factory_func) {
        printf("Unable to load create_klass from DLL!\n");
        ::FreeLibrary(dll_handle);
        return nullptr;
    }
    printf("get create_klass() from DLL!\n");
    // Ask the factory for a new object implementing the IKlass
    // interface
    return factory_func();
#endif
}
