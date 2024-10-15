//
// Created by User on 01.10.2024.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

 static int get_root_value()
{
    int k = 0;
    do
    {
        printf("Enter the value of root (k):\n");
        scanf("%d", &k);
        fflush(stdin);

        if (k == 0)
        {
            printf("The value must not equal to 0. Try again\n");
        }
    }
    while (k == 0);
    return k;
}
static double get_root_base(int (k))
 {
     double x = 0;
     do
     {
         printf("Enter the value of root base (x):\n");
         scanf("%lf", &x);
         fflush(stdin);
         if (k > 0 && k % 2 == 0 && x < 0)
         {
             printf("The value must be positive or zero. Try again\n");
         }
         else if (k < 0 && k % 2 == 0 && x <= 0)
         {
             printf("The value must be positive. Try again\n");
         }
         else if (k < 0 && k % 2 != 0 && x == 0) {
             printf("The value can't be zero. Try again\n");
         }
     } while ((k > 0 && k % 2 == 0 && x < 0) || (k < 0 && k % 2 == 0 && x <= 0) || (k < 0 && k % 2 != 0 && x == 0));

     return x;
 }

static double get_accuracy()
{
    double e = 0;
    char accuracy_option;
    do //попробовать написать валидацию ввода для каждой точности
    {
        printf("Choose the type to enter accuracy (e):\n");
        printf("If the option doesn't lay in one of three categories accuracy will be 0.001 by default\n");
        printf("1. Decimal places\n");
        printf("2. Real number\n");
        printf("3. Exponential form\n");
        scanf(" %c", &accuracy_option);
        fflush(stdin);

        switch (accuracy_option)
        {
            case '1':
                int decimal = 0;
            printf("Enter the number of decimal places:\n");
            scanf("%d", &decimal);
            fflush(stdin);
            e = pow(10, -decimal);
            printf("The accuracy is %.*lf\n", decimal, e);
            break;

            case '2':
                printf("Enter accuracy as a real number (e.g. 0.001):\n");
            scanf("%lf", &e);
            fflush(stdin);
            printf("The accuracy is %lf\n", e);
            break;

            case '3':
                printf("Enter accuracy as an exponential number (e.g. 1e-3):\n");
            scanf("%lf", &e);
            fflush(stdin);
            printf("The accuracy is %e\n", e);
            break;

            default:
                printf("Invalid option, the accuracy is 0.001 by default \n");
            e = 0.001;
            fflush(stdin);
            printf("The accuracy is %lf\n", e);
            break;
        }
    }
    while (accuracy_option < '1' || accuracy_option > '3');
    return e;
}

static int get_decimal_places()
{
    int n = 0;
    do
    {
        printf("Enter the number of decimal places (from 1 to 15):\n");
        scanf("%d", &n);
        if (n < 1 || n > 15)
        {
            printf("Please enter a number between 1 and 15\n");
        }
    }
    while (n < 1 || n > 15);
    return n;
}
#endif //FUNCTIONS_H
