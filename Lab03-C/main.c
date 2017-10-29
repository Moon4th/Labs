#include<stdio.h>
#include<math.h>
int main() {
    double a, x, G, F, Y,xmax,xmin;
    int formula,steps;
    do{
        printf("Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
        printf("Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
        printf("Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
        printf("Enter 0 to quit\n");
        printf("Select the formula:\n");
        scanf("%d", &formula);//Выбор формулы для дальнейших вычислений
        if (formula==0){
            return 0;
        }
        while ((formula < 0) || (formula > 3)) { //Проверка правильности выбора формулы
            printf("Invalid value, try again\n");
            printf("Select the formula:");
            scanf("%d", &formula);
        }
        printf("Enter minimum value of x:");//Ввод минимального значения x
        scanf("%lf",&xmin);
        printf("Enter maximum value of x:");//Ввод максимального значения x
        scanf("%lf",&xmax);
        while (xmin>=xmax){//Цикл проверяющий в правильночти выбор границ x
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %lf\n",xmin);
            printf("Enter maximum value of x again:");
            scanf("%lf",&xmax);
        }
        printf("Enter a (any value):");
        scanf("%lf", &a);
        printf("Enter the number of steps:");//Ввод количества шагов вычисления функции
        scanf("%d",&steps);
        switch (formula) { //Переключение на одну из 3 формулы в зависимости от начального выбора
            case 1: {
                for (x = xmin; x <= xmax; x += (xmax - xmin) /
                                               (steps - 1)) {//Цикл вычисления формулы с учетом данных введенных выше
                    G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    printf("%lf\n", G);
                }
                break;
            }
            case 2: {
                for (x = xmin; x <= xmax; x += (xmax - xmin) / (steps - 1)) {
                    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                    printf("%lf\n", F);
                }
                break;
            }
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
    }while(formula!=0);//Работа программы будет повоторятся до тех пор, пока пользователь не захочет выйти
    return 0;
}
