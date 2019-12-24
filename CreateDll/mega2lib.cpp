#include "mega2lib.h"

Mega2Lib::Mega2Lib()
{
    std::cout << "Mega2Lib created ..." << std::endl;
}

void Mega2Lib::destroy()
{
    std::cout << "Mega2Lib destroyed ..." << std::endl;
    delete this;
}

void Mega2Lib::sayHello()
{
    std::cout << "Hello from the Mega2Lib..." << std::endl;
}
