#include<stdio.h>
#include<math.h>
int main() {
    double a, x, G, F, Y,xmax,xmin;
    int n,steps;
    do{
        printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
        printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
        printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
        printf("Enter 0 to quit\n");
        printf("Select the formula:\n");
        scanf("%d", &n);
        if (n==0){
            return 0;
        }
        while ((n < 0) || (n > 3)) {
            printf("Invalid value, try again\n");
            printf("Select the formula:");
            scanf("%d", &n);
        }
        printf("Enter minimum value of x:");
        scanf("%lf",&xmin);
        printf("Enter maximum value of x:");
        scanf("%lf",&xmax);
        while (xmin>=xmax){
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %lf\n",xmin);
            printf("Enter maximum value of x again:");
            scanf("%lf",&xmax);
        }
        printf("Enter a (any value):");
        scanf("%lf", &a);
        printf("Enter the number of steps");
        scanf("%d",&steps);
        switch (n) { //Выбор формулы
            case 1:
                for(x=xmin;x<=xmax;x += (xmax - xmin) / (steps - 1)){
                    G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    printf("%lf\n", G);
                }
                break;
            case 2:
                for(x=xmin;x<=xmax;x += (xmax - xmin) / (steps - 1)){
                    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                    printf("%lf\n", F);
                }
                break;
            case 3:
                for(x=xmin;x<=xmax;x += (xmax - xmin) / (steps - 1)){
                    if (x < 0)
                    {
                        printf("Error");
                        return 0;
                    }
                    Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                    printf("%lf\n", Y);
                }
                break;
        }
    }while(n!=0);
    return 0;
}
