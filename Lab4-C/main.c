#include<stdio.h>
#include<math.h>
int main() {
    double a, x, G, F, Y,xmax,xmin,amin,amax,minvalue,maxvalue;
    int formula,steps,i,q;
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
        printf("Enter minimum value of x:"); //Ввод минимального значения x
        scanf("%lf",&xmin);
        printf("Enter maximum value of x:"); //Ввод максимального значения x
        scanf("%lf",&xmax);
        while (xmin>=xmax){ //Цикл проверяющий в правильночти выбор границ x
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %lf\n",xmin);
            printf("Enter maximum value of x again:");
            scanf("%lf",&xmax);
        }
        printf("Enter minimum value of a:");//Ввод минимального значения a
        scanf("%lf",&amin);
        printf("Enter maximum value of a:");//Ввод максимального значения a
        scanf("%lf",&amax);
        while (amin>=amax){ //Цикл проверяющий в правильночти выбор границ a
            printf("Maximum value of a should be grater than the minimum\n");
            printf("Minimum value = %lf\n",amin);
            printf("Enter maximum value of a again:");
            scanf("%lf",&amax);
        }
        printf("Enter the number of steps:");//Ввод количества шагов вычисления функции
        scanf("%d",&steps);
        double results[steps];
        switch (formula) { //Переключение на одну из 3 формулы в зависимости от начального выбора
            case 1: {
                for(x=xmin,a=amin,i = 0;x<=xmax, a<=amax, i<steps;x += (xmax - xmin) / (steps - 1),a += (amax - amin) / (steps - 1),i++){//Цикл вычисления формулы с учетом данных введенных выше
                    G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    results[i]=G;
                    printf("x=%lf",x);
                    printf("    G=%lf\n", G);
                }
                break;
            }
            case 2: {
                for(x=xmin,a=amin,i = 0;x<=xmax, a<=amax, i<steps;x += (xmax - xmin) / (steps - 1),a += (amax - amin) / (steps - 1),i++){
                    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                    results[i]=F;
                    printf("x=%lf",x);
                    printf("    F=%lf\n", F);
                }
                break;
            }
            case 3: {
                for(x=xmin,a=amin,i = 0;x<=xmax, a<=amax, i<steps;x += (xmax - xmin) / (steps - 1),a += (amax - amin) / (steps - 1),i++){
                    if (x < 0) {
                        printf("Error");
                        return 0;
                    }
                    Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                    results[i]=Y;
                    printf("x=%lf",x);
                    printf("    Y=%lf\n", Y);
                }
                break;
            }
        }
        for (maxvalue=0,i=0,minvalue=0;i<steps;i++) {//Нахождение максимального и минимального значения
            if (results[i]>maxvalue){
                maxvalue=results[i];
            }
            if (results[i]<minvalue){
                minvalue=results[i];
            }
        }
        printf ("Minimum value=%lf\n",minvalue);
        printf ("Maximum value=%lf\n",maxvalue);
    }while(formula!=0);//Работа программы будет повоторятся до тех пор, пока пользователь не захочет выйти
    return 0;
}