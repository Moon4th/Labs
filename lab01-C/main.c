#include<stdio.h>
#include<math.h>

int main()
{
    double a, x, G, F, Y;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter x: ");
    scanf("%lf", &x);
    G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / (-20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2));
    printf("Result: ");
    printf("%lf", G);

    printf("\n\n Enter a: ");
    scanf("%lf", &a);
    printf("Enter x: ");
    scanf("%lf", &x);
    F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2));
    printf("Result: ");
    printf("%lf", F);

    printf("\n\n Enter a: ");
    scanf("%lf", &a);
    printf("Enter x: ");
    scanf("%lf", &x);
    Y=log(2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1);
    printf("Result: ");
    printf("%lf", Y);

    return 0;
}