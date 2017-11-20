#include<stdio.h>
#include<math.h>

int main()
{
    double a, x, G, F, Y,denominator;
    int formula;
    printf("select the formula\n");
    printf("Formula 1: G = 4*(-4*pow(a,2)+a*x+5*pow(x,2))/-20*pow(a,2)+28*a*x+3*pow(x,2)\n");
    printf("Formula 2: F = atan(24*pow(a,2)-25*a*x+6*pow(x,2)\n");
    printf("Formula 3: Y= log(2*pow(a,2)-7*a*x+6*pow(x,2)+1)\n");
    scanf("%d",&formula);

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter a:");
    scanf("%lf",&a);

        switch (formula) {
            case 1:
                denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                if (denominator == 0) {
                    printf("The input values do not belong to the domain of the function definition");
                    break;
                }
                G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / denominator;
                printf("G =%lf\n", G);
                break;

            case 2:
                F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                printf("F = ");
                printf("%lf", F);
                break;

            case 3:
                if (x < 0 || a < 0) {
                    printf("The input values do not belong to the domain of the function definition");
                    break;
                }
                Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                printf("Y =%lf\n", Y);
                break;

            default:
                printf("Error");
        }
    return 0;
}