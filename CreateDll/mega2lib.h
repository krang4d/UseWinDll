#ifndef MEGA2LIB_H
#define MEGA2LIB_H

#include <iostream>
#include "imegalib.h"

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

extern "C" __declspec(dllexport) imegalib* __cdecl create_klass()
{
    return new Mega2Lib;
}

#endif // MEGA2LIB_H
