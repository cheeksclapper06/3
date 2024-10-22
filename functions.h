//
// Created by User on 01.10.2024.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

 static int get_root_value()
{
    int k = 0;
     printf("Enter the value of root (k):\n");
    do
    {
        if (scanf("%d", &k) != 1)
        {
            printf("Invalid Input, please enter an integer value\n");
            fflush(stdin);
        }
        else if (k == 0)
        {
            printf("The value must not equal to 0. Try again\n");
            fflush(stdin);
        }
    }
    while (k == 0);
     fflush(stdin);
     return k;
}
static double get_root_base(int (k))
 {
     double x = 0;
     do
     {
         printf("Enter the value of the root base (x):\n");
         do
         {
             if (scanf("%lf", &x) != 1)
             {
                 printf("Invalid Input, enter a real number\n");
                 fflush(stdin);
             }
             else
             {
                 fflush(stdin);
                 break;
             }
         }
         while (x != 1);

         if (k > 0 && k % 2 == 0 && x < 0)
         {
             printf("The value must be positive or zero. Try again\n");
         }
         else if (k < 0 && k % 2 == 0 && x <= 0)
         {
             printf("The value must be positive. Try again\n");
         }
         else if (k < 0 && k % 2 != 0 && x == 0)
         {
             printf("The value can't be zero. Try again\n");
         }
     } while ((k > 0 && k % 2 == 0 && x < 0) || (k < 0 && k % 2 == 0 && x <= 0) || (k < 0 && k % 2 != 0 && x == 0));
     fflush(stdin);
     return x;
 }

static double get_accuracy()
{
     int accuracy = 0;
    double e = 0;
    do
    {
        printf("Choose the type to enter accuracy (e):\n");
        printf("If the option doesn't lay in one of three categories accuracy will be 0.001 by default\n");
        printf("1. Decimal places\n");
        printf("2. Real number\n");
        printf("3. Exponential form\n");

        accuracy = getch();
        while (getchar() != '\n');
        switch (accuracy)
        {
            case 49:
                int decimal = 0;
            printf("Enter the number of decimal places:\n");
            do
            {
                if (scanf("%d", &decimal) != 1 || decimal <= 0)
                {
                    printf("Invalid Input, enter a number greater than zero\n");
                    fflush(stdin);
                }
                else
                {
                    fflush(stdin);
                    break;
                }
            }
            while (decimal != 1 || decimal <= 0);
            e = pow(10, -decimal);
            printf("In exponential form the accuracy is %e\n", e);
            break;

            case 50:
                printf("Enter accuracy as a real number (e.g. 0.001):\n");
            do {
                if(scanf("%lf", &e) != 1 || e <= 0)
                {
                    printf("Invalid Input, enter an exponential number greater than zero\n");
                    fflush(stdin);
                }
                else
                {
                    fflush(stdin);
                    break;
                }
            }
            while (e != 1 || e <= 0);
            printf("In exponential form the accuracy is %e\n", e);
            break;

            case 51:
                printf("Enter accuracy as an exponential number (e.g. 1e-3):\n");
            do
            {
                if(scanf("%lf", &e) != 1 || e <= 0)
                {
                    printf("Invalid Input, enter a real number greater than zero\n");
                    fflush(stdin);
                }
                else
                {
                    fflush(stdin);
                    break;
                }
            }
            while (e != 1 || e <= 0);
            printf("The accuracy is %e\n", e);
            break;

            default:
                printf("Invalid option, please enter a given number (1 - 3)\n");
        }
    }
    while (accuracy < 49 || accuracy > 51);
     fflush(stdin);
     return e;
}

#endif //FUNCTIONS_H
