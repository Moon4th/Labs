#include<stdio.h>
#include<math.h>
int main() {
    double a, x, G, F, Y;
    int n;
    do { //цикл
        printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
        printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
        printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
        printf("Enter 0 to quit\n");
        printf("Select the formula:\n");
        scanf("%d", &n);
        while ((n < 0) || (n > 3)) { // Цикл, который поросит ввести значение n снова, если вы ввели некорректно.
            printf("invalid value, try again\n");
            printf("Select the formula:");
            scanf("%d", &n);
        }
        for (;;) { //Ввод границ изменения x
            if(n==0)
            {break;}
            printf("Enter x (from 1 to 10):");
            scanf("%lf", &x);
            printf("Enter a (any value):");
            scanf("%lf", &a);
            if(x<=0 || x>10)
                printf("invalid value of variable x, try to enter again\n");
            if(x<=0 || x>10)continue;
            else break;
        }
        switch (n) { //Выбор формулы
            case 1:
                G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                printf("%lf\n", G);
                break;
            case 2:
                F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                printf("%lf\n", F);
                break;
            case 3:
                Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                printf("%lf\n", Y);
                break;
        }
    }while ((n < 4 && n > 0));  //Цикл

    return 0;
}