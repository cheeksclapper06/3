#include <stdio.h>
#include <math.h>
#include "functions.h"

int main()
{
    double x = 0, e = 0;
    unsigned k = 0;
    char restart = 0;

    do
    {
        printf("\nThis application will calculate the K-th root of an X with specified accuracy (E)\n");

        k = get_root_value();

        do
        {
            printf("Enter the root expression (x)\n");
            scanf("%lf", &x);
            fflush(stdin);
        }
        while (restart == 'y' || restart == 'Y');
        if (restart == 'n' || restart == 'N')
        {
           break;
        }

        e = get_accuracy();

        double delta = 1.0, y = 1.0;
        int i = 1;
        while (fabs(delta) >= e)
        {
            delta = (1.0 / k) * (x /pow(y, k - 1) - y);

            if (fabs(delta) < e)
            {
                break;
            }

            y += delta;
            i++;
        }

        char output_form = 0;
        printf("Choose the output form: standard (1) or exponential (2):\n");
        scanf(" %c", &output_form);
        fflush(stdin);

        if (output_form == '1')
        {
            int n = 0;
            n = get_decimal_places();
            printf("The calculated Y is: %.*lf\n", n, y);

        }
        else if (output_form == '2')
        {
            printf("The calculated Y is: %e\n", y);
        }

        printf ("Do you want to restart?(y/n)");
        scanf(" %c", &restart);
        fflush(stdin);
    }

    while (restart == 'y' || restart == 'Y');
    return 0;
}