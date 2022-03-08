#include "IIR_filter.h"

// constructors
IIR_filter::IIR_filter(float tau,float Ts)
{
    a1 = -tau/(tau+Ts);
    a0 = 0;
    b0 = Ts/(tau+Ts);
    y_old1 = y_old2 = 0;
}

IIR_filter::IIR_filter(float k, float wb, float D, float Ts)
{
    a0 = 1 + wb*wb*Ts*Ts -2.0*D*wb*Ts;
    a1 = 2.0*D*wb*Ts-2;
    b0 = wb*wb*Ts*Ts*k;
    y_old1 = y_old2 = 0;
}
// Methods:

float IIR_filter::eval(float u)
{
    float y = -a1*y_old1 - a0*y_old2 + b0*u;
    y_old2 = y_old1;
    y_old1 = y;
    return y;       // this has to be modified!!!
}


// Deconstructor
IIR_filter::~IIR_filter() {} 