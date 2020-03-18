#ifndef MEGA2LIB_H
#define MEGA2LIB_H

//#include <iostream>
#include "imegalib.h"
#include <stdio.h>

#if defined (__GNUC__) && defined(__unix__)
  #define PRINT_API __attribute__ ((__visibility__("default")))
#elif defined (WIN32)
  #ifdef BUILDING_DLL
    #define PRINT_API __declspec(dllexport)
  #else
    #define PRINT_API __declspec(dllimport)
  #endif
#endif

class Mega2Lib : public imegalib
{
public:
    Mega2Lib();
    virtual ~Mega2Lib() {}

    // imegalib interface
public:
    virtual void destroy() override;
    virtual void sayHello() override;
};

extern "C" PRINT_API imegalib* __cdecl create_klass()
{
    return new Mega2Lib;
}

#endif // MEGA2LIB_H
