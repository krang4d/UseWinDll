#ifndef IMEGALIB_H
#define IMEGALIB_H

#define __cdecl __attribute__((__cdecl__))

class imegalib;

typedef imegalib* (*pclass_factory_t)();

class imegalib
{
public:
    virtual ~imegalib() {}
    virtual void destroy() = 0;
    virtual void sayHello() = 0;
};

#endif // IMEGALIB_H
