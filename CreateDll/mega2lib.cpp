#include "mega2lib.h"

Mega2Lib::Mega2Lib()
{
    printf("Mega2Lib created ...\n");
}

void Mega2Lib::destroy()
{
    printf("Mega2Lib destroyed ...\n");
    delete this;
}

void Mega2Lib::sayHello()
{
    printf("Hello from the Mega2Lib...\n");
}
