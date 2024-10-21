#include <stdio.h>
#include <conio.h>
#include "root_calculations.h"
#include "functions.h"

int main()
{
    double x = 0, e = 0;
    int k = 0;

    do
    {
        printf("This application will calculate the K-th root of an X with specified accuracy (E)\n");

        k = get_root_value();
        x = get_root_base(k);
        e = get_accuracy();

        const double y = calculate_root(k, x, e);

        char output = 0;
        do
        {
            printf("Choose the output form: standard (1) or exponential (2):\n");
            output = getchar();
            while (getchar() != '\n');
            switch (output)
            {
                case 49:
                    int n = 0;
                n = get_decimal_places();
                printf("The calculated Y is: %.*lf\n", n, y);
                continue;

                case 50:
                    printf("The calculated Y is: %e\n", y);
                continue;

                default:
                    printf("You can choose only between number 1 or 2\n");
                break;
            }
        }
        while (output < 49 || output > 51);
        printf ("Do you want to restart?\n");
        printf("If yes press ENTER, otherwise press any key to close the program\n");
    }
    while (getch() == 13);
    fflush(stdin);
    return 0;

}
