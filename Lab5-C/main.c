#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    double a, x, G, F, Y,xmax,xmin,minvalue,maxvalue,denominator;
    int choice,steps,i,number;
    char stepss[256],xmaxs[256],xmins[256],result[256],p[256],snumber[256],template[256],*index;

    printf("1-Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
    printf("2-Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
    printf("3-Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
    printf("4-Program for finding even numerals in the number\n");
    printf("Enter 0 to quit\n");
    printf("Choose what you want:\n");
    scanf("%d", &choice);//Выбор дальнейших действий программы

    while ((choice < 0) || (choice > 4)) { //Проверка правильности выбора
        printf("Invalid value, try again\n");
        printf("Select the formula:");
        scanf("%d", &choice); }

    while (choice != 0){

        if (choice == 4){//Программа для поиска четных цифр в числе
            int ncounter = 0;
            printf("Enter the number:");
            scanf("%s",snumber);
            while (strstr(snumber,".")){//Проверка числа на его тип
                printf ("Enter integer value:\n");
                scanf ("%s",snumber);
            }
            number = atoi(snumber);//Преобразование строки в целое число
            while (number != 0){
                if (number % 2 == 0){//Если при делении числа на 2 остаток 0, обрезает чило и увеличивает счетчик
                    ncounter++;
                    number = number / 10;
                }
                else{//В противном случае просто обрезает число
                    number = number / 10;
                }
            }
            printf ("Amount of even numbers:%d\n",ncounter);

            printf("1-Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
            printf("2-Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
            printf("3-Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
            printf("4-Program for finding even numerals in the number\n");
            printf("Enter 0 to quit\n");
            printf("Choose what you want:\n");
            scanf("%d", &choice);//Выбор дальнейших действий программы

            continue;
        }

        printf("Enter minimum value of x:"); //Ввод минимального значения x
        scanf("%s",&xmins);
        printf("Enter maximum value of x:"); //Ввод максимального значения x
        scanf("%s",&xmaxs);
        xmin = atof(xmins);
        xmax = atof(xmaxs);

        while (xmin>=xmax) { //Цикл проверяющий в правильночти выбор границ x
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %s\n", xmins);
            printf("Enter maximum value of x again:");
            scanf("%s", &xmaxs);
            xmax = atof(xmaxs);
        }

        printf("Enter a:");
        scanf("%lf",&a);
        printf("Enter the number of steps:");//Ввод количества шагов вычисления функции
        scanf("%s",&stepss);
        steps = atoi(stepss);

        while(steps<=0){//Проверка на корректный ввод кол-ва шагов
            printf("Error,the number of steps can not be less than or equal to 0\n");
            printf("Enter the number of steps:");
            scanf("%s",&stepss);
            steps = atoi(stepss);
        }

        double results [steps];
        switch (choice) { //Переключение на одну из 3 формулы в зависимости от начального выбора
            case 1: {
                for(x=xmin,i = 0;x<=xmax, i<steps;x += (xmax - xmin) / (steps - 1),i++){//Цикл вычисления формулы с учетом данных введенных выше
                    denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    if (denominator == 0){
                        printf("The input values do not belong to the domain of the function definition");
                        continue;
                    }
                    G = 4 * ( - 4 * pow (a ,2) + a * x + 5 * pow (x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    results[i]=G;//Сохранение результатов в массив
                    printf("x=%lf",x);
                    printf("\tG=%lf\n", G);
                    sprintf(p,"%lf",results[i]);//Создание строки результатов
                    strcat(result,p);
                }
                break;
            }
            case 2: {
                for(x=xmin,i = 0;x<=xmax, i<steps;x += (xmax - xmin) / (steps - 1),i++){
                    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                    results[i]=F;
                    printf("x=%lf",x);
                    printf("\tF=%lf\n", F);
                    sprintf(p,"%lf",results[i]);
                    strcat(result,p);
                }
                break;
            }
            case 3: {
                for(x=xmin,i = 0;x<=xmax, i<steps;x += (xmax - xmin) / (steps - 1),i++){
                    if (x < 0 || a < 0) {
                        printf("The input values do not belong to the domain of the function definition");
                    }
                    Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                    results[i]=Y;
                    printf("x=%lf",x);
                    printf("\tY=%lf\n", Y);
                    sprintf(p,"%lf",results[i]);
                    strcat(result,p);
                }
                break;
            }
        }

        for (maxvalue=0,i=0,minvalue=results[0];i<steps;i++) {//Нахождение максимального и минимального значения
            if (results[i]>maxvalue){
                maxvalue=results[i];
            }
            if (results[i]<minvalue){
                minvalue=results[i];
            }
        }
        printf ("Minimum value=%lf\n",minvalue);
        printf ("Maximum value=%lf\n",maxvalue);
        printf ("Result string-%s\n",result);

        int counter = 0;//Поиск совпадений
        printf ("Enter the template:\n");
        scanf ("%s",template);//Шаблон
        index = strstr(result, template);//Находит место совпадения
        while(index){//Пока есть совпадение...
            sprintf(result,index +1);//Обрезает все лишнее у строки
            counter++;
            index = strstr(result, template);
        }
        printf("Number of coincidences: %d\n",counter);

        printf("1-Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
        printf("2-Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
        printf("3-Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
        printf("4-Program for finding even numerals in the number\n");
        printf("Enter 0 to quit\n");
        printf("Choose what you want:\n");
        scanf("%d", &choice);//Выбор дальнейших действий программы

        while ((choice < 0) || (choice > 4)) { //Проверка правильности выбора
            printf("Invalid value, try again\n");
            printf("Select the formula:");
            scanf("%d", &choice); }

    }

    printf ("Shutdown...");
    return 0;
}