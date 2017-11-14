#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define length 100
FILE *file;

int main() {

    double a, x, G, F, Y,xmax,xmin,minvalue,maxvalue,denominator,finalmaxvalue,finalminvalue;
    int choice,steps,i,number,ncounter = 0,counter = 0;
    char stepss[256],xmaxs[256],xmins[256],result[256] = {0},p[256],snumber[256],template[256],*index,Gresult[256] = {0},Fresult[256] = {0},Yresult[256] = {0};
    struct mass {
        double  values [length];
    }results;

    printf ("Enter 1 to start the program\n");
    printf ("Enter 0 to quit");
    scanf ("%d",&choice);

    while ((choice < 0) || (choice > 1)) { //Проверка правильности выбора
        printf("Invalid value, try again\n");
        printf("Enter again:");
        scanf("%d", &choice); }

    while (choice != 0) {

        //Программа для поиска четных цифр в числе
        printf("Enter the number:");
        scanf("%s", snumber);
        while (strstr(snumber, ".")) {//Проверка числа на его тип
            printf("Enter integer value:\n");
            scanf("%s", snumber);
        }
        number = atoi(snumber);//Преобразование строки в целое число
        while (number != 0) {
            if (number % 2 == 0) {//Если при делении числа на 2 остаток 0, обрезает чило и увеличивает счетчик
                ncounter++;
                number = number / 10;
            } else {//В противном случае просто обрезает число
                number = number / 10;
            }
        }
        printf("Amount of even numbers:%d\n", ncounter);

        printf("Enter minimum value of x:"); //Ввод минимального значения x
        scanf("%s", &xmins);
        printf("Enter maximum value of x:"); //Ввод максимального значения x
        scanf("%s", &xmaxs);
        xmin = atof(xmins);
        xmax = atof(xmaxs);

        while (xmin >= xmax) { //Цикл проверяющий в правильночти выбор границ x
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %s\n", xmins);
            printf("Enter maximum value of x again:");
            scanf("%s", &xmaxs);
            xmax = atof(xmaxs);
        }

        printf("Enter a:");
        scanf("%lf", &a);

        printf("Enter the number of steps:");//Ввод количества шагов вычисления функции
        scanf("%s", &stepss);
        steps = atoi(stepss);

        while (steps <= 0) {//Проверка на корректный ввод кол-ва шагов
            printf("Error,the number of steps can not be less than or equal to 0\n");
            printf("Enter the number of steps:");
            scanf("%s", &stepss);
            steps = atoi(stepss);
        }

        for (x = xmin, i = 0; x <= xmax, i < steps; x += (xmax - xmin) / (steps -
                                                                          1), i++) {//Цикл вычисления формулы с учетом данных введенных выше
            if (i>=length){
                printf ("Error, calculations can not continue, because the array ended\n");
                break;
            }
            denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
            if (denominator == 0) {
                printf("The input values do not belong to the domain of the function definition");
                continue;
            }
            G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
            results.values[i] = G;//Сохранение результатов в массив
            file = fopen("C:\\Users\\Nikita\\ClionProjects\\lab7\\text.txt","w+");
            fprintf(file, "%lf\n", results.values[i]);
            results.values[i] = 0;
            fseek(file,0,SEEK_SET);
            fscanf (file,"%lf",&results.values[i]);
            fseek(file,+1,SEEK_CUR);

            printf("x=%lf", x);
            printf("\tG=%lf\n", results.values[i]);
            sprintf(p, "%lf", results.values[i]);//Создание строки результатов
            strcat(result, p);
            strcat(Gresult,p);
        }
        fclose (file);

        for (maxvalue = 0, i = 0, minvalue = results.values[0];
             i < steps; i++) {//Нахождение максимального и минимального значения
            if (i>length){
                break;
            }
            if (results.values[i] > maxvalue)
                maxvalue = results.values[i];
            if (results.values[i] < minvalue)
                minvalue = results.values[i];
        }
        finalmaxvalue = maxvalue;
        finalminvalue = minvalue;

        printf("Minimum value=%lf\n", minvalue);
        printf("Maximum value=%lf\n", maxvalue);
        printf("Result string-%s\n", Gresult);

        counter = 0;//Поиск совпадений
        printf("Enter the template:\n");
        scanf("%s", template);//Шаблон
        index = strstr(Gresult, template);//Находит место совпадения
        while (index) {//Пока есть совпадение...
            sprintf(Gresult, index + 1);//Обрезает все лишнее у строки
            counter++;
            index = strstr(Gresult, template);
        }
        printf("Number of coincidences: %d\n", counter);

        for (i=0;i<length;i++){
            results.values[i] = 0;
        }

        for (x = xmin, i = 0; x <= xmax, i < steps; x += (xmax - xmin) / (steps - 1), i++) {
            F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
            results.values[i] = F;
            file = fopen("C:\\Users\\Nikita\\ClionProjects\\lab7\\text.txt","w+");
            fprintf(file, "%lf\n", results.values[i]);
            results.values[i] = 0;
            fseek(file,0,SEEK_SET);
            fscanf (file,"%lf",&results.values[i]);
            fseek(file,+1,SEEK_CUR);
            printf("x=%lf", x);
            printf("\tF=%lf\n", results.values[i]);
            sprintf(p, "%lf", results.values[i]);
            strcat(result, p);
            strcat (Fresult,p);
        }
        fclose (file);

        for (maxvalue = 0, i = 0, minvalue = results.values[0];
             i < steps; i++) {//Нахождение максимального и минимального значения
            if (results.values[i] > maxvalue)
                maxvalue = results.values[i];
            if (results.values[i] < minvalue)
                minvalue = results.values[i];
            if (maxvalue > finalmaxvalue)
                finalmaxvalue = maxvalue;
            if (minvalue < finalminvalue)
                finalminvalue = minvalue;
        }
        printf("Minimum value=%lf\n", minvalue);
        printf("Maximum value=%lf\n", maxvalue);
        printf("Result string-%s\n", Fresult);

        counter = 0;//Поиск совпадений
        printf("Enter the template:\n");
        scanf("%s", template);//Шаблон
        index = strstr(Fresult, template);//Находит место совпадения
        while (index) {//Пока есть совпадение...
            sprintf(Fresult, index + 1);//Обрезает все лишнее у строки
            counter++;
            index = strstr(Fresult, template);
        }
        printf("Number of coincidences: %d\n", counter);

        for (i=0;i<length;i++){
            results.values[i] = 0;
        }

        for (x = xmin, i = 0; x <= xmax, i < steps; x += (xmax - xmin) / (steps - 1), i++) {
            if (x < 0 || a < 0) {
                printf("The input values do not belong to the domain of the function definition");
            }
            Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
            results.values[i] = Y;
            file = fopen("C:\\Users\\Nikita\\ClionProjects\\lab7\\text.txt","w+");
            fprintf(file, "%lf\n", results.values[i]);
            results.values[i] = 0;
            fseek(file,0,SEEK_SET);
            fscanf (file,"%lf",&results.values[i]);
            fseek(file,+1,SEEK_CUR);
            printf("x=%lf", x);
            printf("\tY=%lf\n", results.values[i]);
            sprintf(p, "%lf", results.values[i]);
            strcat(result, p);
            strcat (Yresult,p);
        }
        fclose (file);

        for (maxvalue = 0, i = 0, minvalue = results.values[0];
             i < steps; i++) {//Нахождение максимального и минимального значения
            if (results.values[i] > maxvalue)
                maxvalue = results.values[i];
            if (results.values[i] < minvalue)
                minvalue = results.values[i];
            if (maxvalue > finalmaxvalue)
                finalmaxvalue = maxvalue;
            if (minvalue < finalminvalue)
                finalminvalue = minvalue;
        }
        printf("Minimum value=%lf\n", minvalue);
        printf("Maximum value=%lf\n", maxvalue);
        printf("Result string-%s\n", Yresult);

        counter = 0;//Поиск совпадений
        printf("Enter the template:\n");
        scanf("%s", template);//Шаблон
        index = strstr(Yresult, template);//Находит место совпадения
        while (index) {//Пока есть совпадение...
            sprintf(Yresult, index + 1);//Обрезает все лишнее у строки
            counter++;
            index = strstr(Yresult, template);
        }
        printf("Number of coincidences: %d\n", counter);

        printf ("Final maximum value = %lf\n",finalmaxvalue);
        printf ("Final minimum value = %lf\n",finalminvalue);
        printf("Final result string-%s\n", result);

        counter = 0;//Поиск совпадений
        printf("Enter the template:\n");
        scanf("%s", template);//Шаблон
        index = strstr(result, template);//Находит место совпадения
        while (index) {//Пока есть совпадение...
            sprintf(result, index + 1);//Обрезает все лишнее у строки
            counter++;
            index = strstr(result, template);
        }
        printf("Number of coincidences: %d\n", counter);

        for (i=0;i<length;i++){
            results.values[i] = 0;
        }

        printf("Enter 1 to continue the program\n");
        printf("Enter 0 to quit");
        scanf("%d", &choice);
        fclose (file);

    }
    printf ("Shutdown...");
    return 0;
}