#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define size 100
#define str 256

int main() {
    double a, x, G, F, Y, x_max, x_min, minvalue, maxvalue, denominator, results[size];
    int choice = 1, steps, i, counter=0;
    char steps_s[str], x_max_s[str], x_min_s[str], result[str] = {0}, p[str], template[str], *index;

    while (choice != 0){

        printf("1-Formula 1: G = 4*(-4 * pow(a, 2) +a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x+ 3 * pow(x, 2)\n");
        printf("2-Formula 2: F = atan (24 * pow(a,2) - 25 * a * x + 6 * pow (x,2)\n");
        printf("3-Formula 3: Y= log (2 * pow(a,2) - 7 * a * x + 6 * pow (x,2) + 1)\n");
        printf("Enter 0 to quit\n");
        printf("Choose what you want:\n");
        scanf("%d", &choice);

        while ((choice < 0) || (choice > 3)) {
            printf("Invalid value, try again\n");
            printf("Select the formula:");
            scanf("%d", &choice);
        }
        if (choice == 0) {
            break;
        }

        printf("Enter minimum value of x:");
        scanf("%s",x_min_s);
        printf("Enter maximum value of x:");
        scanf("%s",x_max_s);
        x_min = atof(x_min_s);
        x_max = atof(x_min_s);

        while (x_min>=x_max) {
            printf("Maximum value of x should be grater than the minimum\n");
            printf("Minimum value = %s\n", x_min_s);
            printf("Enter maximum value of x again:");
            scanf("%s", x_max_s);
            x_max = atof(x_max_s);
        }

        printf("Enter a:");
        scanf("%lf",&a);
        printf("Enter the number of steps,not more than %d:",size);
        scanf("%s",steps_s);
        steps = atoi(steps_s);

        while(steps<=0){
            printf("Error,the number of steps can not be less than or equal to 0\n");
            printf("Enter the number of steps,not more than %d:",size);
            scanf("%s",steps_s);
            steps = atoi(steps_s);
        }
        if (steps>=size){
            printf ("Error,too many steps\n");
            break;
        }

        switch (choice) {
            case 1:
                for(x=x_min,i = 0;x<=x_max, i<steps;x += (x_max - x_min) / (steps - 1),i++){
                    denominator = -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    if (denominator == 0){
                        printf("The input values do not belong to the domain of the function definition");
                        continue;
                    }
                    G = 4 * ( - 4 * pow (a ,2) + a * x + 5 * pow (x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2);
                    results[i]=G;
                    printf("x=%lf\tG=%lf\n",x,G);
                }
                break;

            case 2:
                for(x=x_min,i = 0;x<=x_max, i<steps;x += (x_max - x_min) / (steps - 1),i++){
                    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2));
                    results[i]=F;
                    printf("x=%lf\tG=%lf\n",x,F);
                }
                break;

            case 3:
                for(x=x_min,i = 0;x<=x_max, i<steps;x += (x_max - x_min) / (steps - 1),i++){
                    if (x < 0 || a < 0) {
                        printf("The input values do not belong to the domain of the function definition");
                    }
                    Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1);
                    results[i]=Y;
                    printf("x=%lf\tG=%lf\n",x,Y);
                }
                break;

            default:
                break;
        }

        for (maxvalue=0,i=0,minvalue=results[0];i<steps;i++) {
            if (results[i]>maxvalue){
                maxvalue=results[i];
            }
            if (results[i]<minvalue){
                minvalue=results[i];
            }
        }

        for (i=0;i<steps;i++){
            sprintf(p,"%lf",results[i]);
            strcat(result,p);
        }

        printf ("Minimum value=%lf\n",minvalue);
        printf ("Maximum value=%lf\n",maxvalue);
        printf ("Result string-%s\n",result);

        printf ("Enter the template:\n");
        scanf ("%s",template);
        index = strstr(result, template);
        while(index){
            sprintf(result,index +1);
            counter++;
            index = strstr(result, template);
        }
        printf("Number of coincidences: %d\n",counter);

        memset (results,0,size);
    }
    printf ("Shutdown...");
    return 0;
}