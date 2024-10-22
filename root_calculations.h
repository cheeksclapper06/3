//
// Created by User on 15.10.2024.
//

#ifndef ROOT_CALCULATIONS_H
#define ROOT_CALCULATIONS_H

#include <math.h>
static double calculate_root(int k, double x, const double e)
{
    double delta = 1.0, y = 1.0;
    do
    {
        while (fabs(delta) >= e)
        {
            if (k < 0)
            {
                k = -k;
                x = 1.0 / x;
                delta = 1.0 / (double)k * (x / pow(y, (double)k - 1.0) - y);
                y += delta;
            }
            else
            {
                delta = 1.0 / (double)k * (x / pow(y, (double)k - 1.0) - y);
                y += delta;
            }
        }
    }
    while (fabs(delta) >= e);
    return y;
}
#endif //ROOT_CALCULATIONS_H
