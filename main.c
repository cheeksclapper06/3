#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "functions.h"

//всем сканф написать валидацию для ввода символов, чтобы выводилась ошибка и цикл повторялся
int main()
{
    double x = 0, e = 0;
    int k = 0;

    do
    {
        printf("This application will calculate the K-th root of an X with specified accuracy (E)\n");

        k = get_root_value();

        //PROBLEM SOS SOS SOS написать нормальную валидацию для икса
            printf("Enter the root expression (x)\n");
            scanf("%lf", &x);
            fflush(stdin);

        e = get_accuracy();

        double delta = 1.0, y = 1.0;
        int i = 1;
        while (fabs(delta) >= e)
        {
            delta = (1.0 / k) * (x / (int)pow(y, k - 1) - y);

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
        //пофиксить проблему с getchar
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
        printf ("Do you want to restart?\n");
        printf("If yes press ENTER, otherwise press any key to close the program\n");
    }
    while (getchar() != 13);
    fflush(stdin);
    return 0;
}
