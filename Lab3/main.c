#include<stdio.h>
#include<math.h>
int main() {
    double a, x, G, F, Y, x_max = 0, x_min = 0, denominator;
    int choice = 1, steps;

        while (choice != 0) {

            printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
            printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
            printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
            printf("Enter 0 to quit\n");
            printf("Select what tou want:\n");
            scanf("%d", &choice);

            while ((choice < 0) || (choice > 3)) {
                printf("Invalid value, try again\n");
                printf("Select what tou want:");
                scanf("%d", &choice);
            }
            if (choice == 0) {
                break;
            }

            printf("Enter minimum value of x:");
            scanf("%lf", &x_min);
            printf("Enter maximum value of x:");
            scanf("%lf", &x_min);
            while (x_min >= x_max) {
                printf("Maximum value of x should be grater than the minimum\n");
                printf("Minimum value = %lf\n", x_min);
                printf("Enter maximum value of x again:");
                scanf("%lf", &x_max);
            }

            printf("Enter a :");
            scanf("%lf", &a);

            printf("Enter the number of steps:");
            scanf("%d", &steps);
            while (steps <= 0) {
                printf("Error,the number of steps can not be less than or equal to 0\n");
                printf("Enter the number of steps:");
                scanf("%d", &steps);
            }

            switch (choice) {
                case 1:
                    for (x = x_min; x <= x_max;) {
                        denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                        if (denominator == 0) {
                            printf("The input values do not belong to the domain of the function definition");
                            continue;
                        }
                        G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                        printf("G=%lf\n", G);
                        x += (x_max - x_min) / (steps - 1);
                    }
                    break;

                case 2:
                    for (x = x_min; x <= x_max; ) {
                        F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                        printf("F=%lf\n", F);
                        x += (x_max - x_min) / (steps - 1);
                    }
                    break;

                case 3:
                    for (x = x_min; x <= x_max;) {
                        if (x < 0 || a < 0) {
                            printf("The input values do not belong to the domain of the function definition");
                        }
                        Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                        printf("Y=%lf\n", Y);
                        x += (x_max - x_min) / (steps - 1);
                    }
                    break;

                default:
                    break;
            }
        }
    printf ("Shutdown...");
    return 0;
}
