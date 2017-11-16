#include<stdio.h>
#include<math.h>
int main() {
    double a, x, G, F, Y, xmax, xmin, denominator;
    int choice = 1, steps;

        while (choice != 0) {

            printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
            printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
            printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
            printf("Enter 0 to quit\n");
            printf("Select what tou want:\n");
            scanf("%d", &choice);//Выбор дальнейших действий программы

            while ((choice < 0) || (choice > 3)) { //Проверка правильности выбора формулы
                printf("Invalid value, try again\n");
                printf("Select the formula:");
                scanf("%d", &choice);
            }
            if (choice == 0) {
                break;
            }

            printf("Enter minimum value of x:");//Ввод минимального значения x
            scanf("%lf", &xmin);
            printf("Enter maximum value of x:");//Ввод максимального значения x
            scanf("%lf", &xmax);
            while (xmin >= xmax) {//Цикл проверяющий в правильность выбора границ x
                printf("Maximum value of x should be grater than the minimum\n");
                printf("Minimum value = %lf\n", xmin);
                printf("Enter maximum value of x again:");
                scanf("%lf", &xmax);
            }

            printf("Enter a :");
            scanf("%lf", &a);

            printf("Enter the number of steps:");//Ввод количества шагов вычисления функции
            scanf("%d", &steps);
            while (steps <= 0) {//Проверка на корректный ввод кол-ва шагов
                printf("Error,the number of steps can not be less than or equal to 0\n");
                printf("Enter the number of steps:");
                scanf("%d", &steps);
            }

            switch (choice) { //Переключение на одну из 3 формулы в зависимости от начального выбора
                case 1: {
                    for (x = xmin; x <= xmax; x += (xmax - xmin) /
                                                   (steps - 1)) {//Цикл вычисления функции с учетом введенных данных
                        denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                        if (denominator == 0) {
                            printf("The input values do not belong to the domain of the function definition");
                            continue;
                        }
                        G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                        printf("G=%lf\n", G);
                    }
                    break;
                }
                case 2: {
                    for (x = xmin; x <= xmax; x += (xmax - xmin) / (steps - 1)) {
                        F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                        printf("F=%lf\n", F);
                    }
                    break;
                }
                case 3: {
                    for (x = xmin; x <= xmax; x += (xmax - xmin) / (steps - 1)) {
                        if (x < 0 || a < 0) {
                            printf("The input values do not belong to the domain of the function definition");
                        }
                        Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                        printf("Y=%lf\n", Y);
                    }
                    break;
                }
            }
        }
    printf ("Shutdown...");
    return 0;
}
