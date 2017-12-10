#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define size 100
#define str 256
FILE *file;

int main() {

    double a, x, G, F, Y, x_max, x_min, minvalue, maxvalue, denominator, final_maxvalue, final_minvalue;
    int choice = 1, steps, i, counter = 0;
    char steps_s[str], x_max_s[str], x_min_s[str], result[str] = {0}, p[str], template[str];
    char *index, G_result[str] = {0}, F_result[str] = {0}, Y_result[str] = {0};
    char file_name[str] = "C:\\Users\\Nikita\\ClionProjects\\lab7\\Values.txt";
    typedef struct {
        double  values;
    }value;
    value results[size];

    while (choice != 0) {

        printf ("Enter 1 to start the program\n");
        printf ("Enter 0 to quit");
        scanf ("%d",&choice);
        while ((choice < 0) || (choice > 1)) {
            printf("Invalid value, try again\n");
            printf("Enter again:");
            scanf("%d", &choice); }
        if (choice == 0) {
            break;
        }

        printf("Enter minimum value of x:");
        scanf("%s", x_min_s);
        printf("Enter maximum value of x:");
        scanf("%s", x_max_s);
        x_min = atof(x_min_s);
        x_max = atof(x_max_s);

        while (x_min >= x_max) {
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %s\n", x_min_s);
            printf("Enter maximum value of x again:");
            scanf("%s", x_max_s);
            x_max = atof(x_max_s);
        }

        printf("Enter a:");
        scanf("%lf", &a);

        printf("Enter the number of steps,not more than %d:",size);
        scanf("%s", steps_s);
        steps = atoi(steps_s);
        while (steps <= 0) {//Проверка на корректный ввод кол-ва шагов
            printf("Error,the number of steps can not be less than or equal to 0\n");
            printf("Enter the number of steps,not more than %d:",size);
            scanf("%s", steps_s);
            steps = atoi(steps_s);
        }
        if (steps>=size){
            printf ("Error,too many steps\n");
            break;
        }

        file = fopen(file_name,"w+");
        printf("data before:\n\n");

        for (x = x_min, i = 0; x <= x_max, i < steps; x += (x_max - x_min) / (steps -
                                                                          1), i++) {
            denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
            if (denominator == 0) {
                printf("The input values do not belong to the domain of the function definition");
                continue;
            }
            G = 4 * (-4 * pow(a, 2) + a * x + 5 * pow(x, 2)) / denominator;
            results[i].values = G;
            fprintf(file, "%lf\n", results[i].values);
            printf("x = %lf", x);
            printf("\tG = %lf\n", results[i].values);
            results[i].values = 0;
        }

        printf("\ndata after:\n\n");

        fseek(file,0,SEEK_SET);
        for (i = 0, x = x_min; i < steps;x += (x_max - x_min) / (steps - 1),i++){
            fscanf (file,"%lf",&results[i].values);
            printf("x = %lf", x);
            printf("\tG = %lf\n", results[i].values);
        }

        for (maxvalue = 0, i = 0, minvalue = results[0].values;
             i < steps; i++) {//Нахождение максимального и минимального значения
            if (results[i].values > maxvalue)
                maxvalue = results[i].values;
            if (results[i].values < minvalue)
                minvalue = results[i].values;
        }
        final_maxvalue = maxvalue;
        final_minvalue = minvalue;

        for (i=0;i<steps;i++){
            sprintf(p,"%lf",results[i].values);
            strcat(result,p);
            strcat(G_result,p);
        }

        printf("\nMinimum value = %lf\n", minvalue);
        printf("Maximum value = %lf\n", maxvalue);
        printf("Result string - %s\n", G_result);

        counter = 0;
        printf("Enter the template:\n");
        scanf("%s", template);
        index = strstr(G_result, template);
        while (index) {
            sprintf(G_result, index + 1);
            counter++;
            index = strstr(G_result, template);
        }
        printf("Number of coincidences: %d\n\n", counter);

        printf("**********************************\n\n");

        file = fopen(file_name,"w+");
        printf("data before:\n\n");

        for (x = x_min, i = 0; x <= x_max, i < steps; x += (x_max - x_min) / (steps - 1), i++) {
            F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
            results[i].values = F;
            fprintf(file, "%lf\n", results[i].values);
            printf("x = %lf", x);
            printf("\tF = %lf\n", results[i].values);
            results[i].values = 0;
        }

        printf("\ndata after:\n\n");

        fseek(file,0,SEEK_SET);
        for (i = 0, x = x_min; i < steps;x += (x_max - x_min) / (steps - 1),i++){
            fscanf (file,"%lf",&results[i].values);
            printf("x = %lf", x);
            printf("\tF = %lf\n", results[i].values);
        }

        for (maxvalue = 0, i = 0, minvalue = results[0].values;
             i < steps; i++) {
            if (results[i].values > maxvalue)
                maxvalue = results[i].values;
            if (results[i].values < minvalue)
                minvalue = results[i].values;
            if (maxvalue > final_maxvalue)
                final_maxvalue = maxvalue;
            if (minvalue < final_minvalue)
                final_minvalue = minvalue;
        }

        for (i=0;i<steps;i++){
            sprintf(p,"%lf",results[i].values);
            strcat(result,p);
            strcat(F_result,p);
        }

        printf("\nMinimum value = %lf\n", minvalue);
        printf("Maximum value = %lf\n", maxvalue);
        printf("Result string - %s\n", F_result);

        counter = 0;
        printf("Enter the template:\n");
        scanf("%s", template);
        index = strstr(F_result, template);
        while (index) {
            sprintf(F_result, index + 1);
            counter++;
            index = strstr(F_result, template);
        }
        printf("Number of coincidences: %d\n\n", counter);


        printf("**********************************\n\n");

        file = fopen(file_name,"w+");
        printf("data before:\n\n");

        for (x = x_min, i = 0; x <= x_max, i < steps; x += (x_max - x_min) / (steps - 1), i++) {
            if (x < 0 || a < 0) {
                printf("The input values do not belong to the domain of the function definition");
            }
            Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
            results[i].values = Y;
            fprintf(file, "%lf\n", results[i].values);
            printf("x = %lf", x);
            printf("\tY = %lf\n", results[i].values);
            results[i].values = 0;
        }

        printf("\ndata after:\n\n");

        fseek(file,0,SEEK_SET);
        for (i = 0, x = x_min; i < steps;x += (x_max - x_min) / (steps - 1),i++){
            fscanf (file,"%lf",&results[i].values);
            printf("x = %lf", x);
            printf("\tY = %lf\n", results[i].values);
        }

        for (maxvalue = 0, i = 0, minvalue = results[i].values;
             i < steps; i++) {
            if (results[i].values > maxvalue)
                maxvalue = results[i].values;
            if (results[i].values < minvalue)
                minvalue = results[i].values;
            if (maxvalue > final_maxvalue)
                final_maxvalue = maxvalue;
            if (minvalue < final_minvalue)
                final_minvalue = minvalue;
        }

        for (i=0;i<steps;i++){
            sprintf(p,"%lf",results[i].values);
            strcat(result,p);
            strcat(Y_result,p);
        }

        printf("\nMinimum value = %lf\n", minvalue);
        printf("Maximum value = %lf\n", maxvalue);
        printf("Result string - %s\n", Y_result);

        counter = 0;
        printf("Enter the template:\n");
        scanf("%s", template);
        index = strstr(Y_result, template);
        while (index) {
            sprintf(Y_result, index + 1);
            counter++;
            index = strstr(Y_result, template);
        }
        printf("Number of coincidences: %d\n", counter);

        printf ("\nFinal maximum value = %lf\n",final_maxvalue);
        printf ("Final minimum value = %lf\n",final_minvalue);
        printf("Final result string - %s\n", result);

        counter = 0;
        printf("Enter the template:\n");
        scanf("%s", template);
        index = strstr(result, template);
        while (index) {
            sprintf(result, index + 1);
            counter++;
            index = strstr(result, template);
        }
        printf("Number of coincidences: %d\n", counter);

        fclose (file);
    }
    printf ("Shutdown...");
    return 0;
}