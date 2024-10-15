//
// Created by User on 15.10.2024.
//

#ifndef ROOT_CALCULATIONS_H
#define ROOT_CALCULATIONS_H

#include <math.h>
static double calculate_root(const int k, const double x, const double e)
{
    double delta = 1.0, y = 1.0;
    do
    {
        while (fabs(delta) >= e)
        {
            delta = (1.0 / k) * (x / pow(y, k - 1) - y);
            y += delta;
        }
    }
    while (fabs(delta) >= e);
    return y;
}
#endif //ROOT_CALCULATIONS_H
