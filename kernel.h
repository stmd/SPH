#ifndef KERNEL_H_
#define KERNEL_H_

#include "kvector.h"

class Kernel
{
public:
    virtual ~Kernel() {}
    virtual double W(double r) = 0;
    virtual Kvector gradW(Kvector vec1, Kvector vec2) = 0;
};

#endif  // KERNEL_H_