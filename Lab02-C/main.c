#include<stdio.h>
#include<math.h>

int main()
{
    double a, x, G, F, Y;
    int n;
    printf("select the formula\n");
    printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / (-20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
    printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
    printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
    scanf("%d",&n);
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter a:");
    scanf("%lf",&a);

    switch (n) {
        case 1:
            G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / (-20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2));
            printf("Result: ");
            printf("%lf", G);
            break;
        case 2:
            F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
            printf("Result: ");
            printf("%lf", F);
            break;
        case 3:
            if (x > -1) {
                printf("Error");
            }
            Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
            printf("Result: ");
            printf("%lf", Y);
            break;

        default:
            printf("Error");
    }
    return 0;
}