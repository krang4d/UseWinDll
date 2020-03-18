#ifndef IMEGALIB_H
#define IMEGALIB_H

struct imegalib;

typedef imegalib* iklass_factory();

struct imegalib
{
    virtual void destroy() = 0;
    virtual void sayHello() = 0;
};

#endif // IMEGALIB_H
