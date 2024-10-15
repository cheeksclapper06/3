#include <stdio.h>
#include "root_calculations.h"
#include "functions.h"

//всем сканф написать валидацию для ввода символов, чтобы выводилась ошибка и цикл повторялся
int main()
{
    double x = 0, e = 0, y = 0;
    int k = 0;

    do
    {
        printf("This application will calculate the K-th root of an X with specified accuracy (E)\n");

        k = get_root_value();

        x = get_root_base(k);
        e = get_accuracy();

        y = calculate_root(k, x, e);

        char output_form = 0;
        do
        {
            printf("Choose the output form: standard (1) or exponential (2):\n");
            scanf(" %c", &output_form);
            fflush(stdin);
            //пофиксить проблему с getchar
            switch (output_form)
            {
                case '1':
                    int n = 0;
                n = get_decimal_places();
                printf("The calculated Y is: %.*lf\n", n, y);
                break;

                case '2':
                    printf("The calculated Y is: %e\n", y);
                break;

                default:
                    printf("You can choose only between number 1 or 2\n");
                break;
            }
        }
        while (output_form < '1' && output_form > '2');
        printf ("Do you want to restart?\n");
        printf("If yes press ENTER, otherwise press any key to close the program\n");
    }
    while (getchar() != 13);
    fflush(stdin);
    return 0;

}
