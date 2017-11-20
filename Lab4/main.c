#include <stdio.h>
#include <math.h>
#include <string.h>
#define size 100

int main() {
    double a, x, G, F, Y, x_max = 0, x_min = 0, minvalue, maxvalue, denominator, results[size];
    int choice = 1, i , steps;

    while (choice != 0){

        printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
        printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
        printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
        printf("Enter 0 to quit\n");
        printf("Select the formula:\n");
        scanf("%d", &choice);
        while ((choice < 0) || (choice > 3)) {
            printf("Invalid value, try again\n");
            printf("Select the formula:");
            scanf("%d", &choice);
        }
        if (choice == 0) {
            break;
        }

        printf("Enter minimum value of x:");
        scanf("%lf",&x_min);
        printf("Enter maximum value of x:");
        scanf("%lf",&x_max);
        while (x_min>=x_max) {
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %lf\n", x_min);
            printf("Enter maximum value of x again:");
            scanf("%lf", &x_max);
        }

        printf("Enter a:");
        scanf("%lf",&a);

        printf("Enter the number of steps,not more than %d:", size);
        scanf("%d",&steps);
        while(steps<=0){//Проверка на корректный ввод кол-ва шагов
            printf("Error,the number of steps can not be less than or equal to 0\n");
            printf("Enter the number of steps,not more than %d:",size);
            scanf("%d",&steps);
        }
        if (steps>=size){
            printf ("Error,too many steps\n");
            break;
        }

        switch (choice) { //Переключение на одну из 3 формулы в зависимости от начального выбора
            case 1:
                for(x=x_min,i = 0;x<=x_max, i<steps;x += (x_max - x_min) / (steps - 1),i++){
                    denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    if (denominator == 0){
                        printf("The input values do not belong to the domain of the function definition");
                        continue;
                    }
                    G = 4 * ( - 4 * pow (a ,2) + a * x + 5 * pow (x, 2)) / denominator;
                    results[i]=G;
                    printf("x =%lf\tG =%lf\n",x,G);
                }
                break;

            case 2:
                for(x=x_min,i = 0;x<=x_max, i<steps;x += (x_max - x_min) / (steps - 1),i++){
                    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                    results[i]=F;
                    printf("x =%lf\tG =%lf\n",x,F);
                }
                break;

            case 3:
                for(x=x_min,i = 0;x<=x_max, i<steps;x += (x_max - x_min) / (steps - 1),i++){
                    if (x < 0 || a < 0) {
                        printf("The input values do not belong to the domain of the function definition");
                        continue;
                    }
                    Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                    results[i]=Y;
                    printf("x =%lf\tG =%lf\n",x,Y);
                }
                break;

            default:
                break;
        }

        for (maxvalue=0,i=0,minvalue=results[0];i<steps;i++) {
            if (results[i]>maxvalue){
                maxvalue=results[i];
            }
            if (results[i]<minvalue){
                minvalue=results[i];
            }
        }
        printf ("Minimum value=%lf\n",minvalue);
        printf ("Maximum value=%lf\n",maxvalue);

        memset (results,0,size);
    }
    printf ("Shutdown...");
    return 0;
}