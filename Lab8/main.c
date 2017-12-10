#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define size 5000
FILE *t, *coordinates_x, *coordinates_y;

void coordinates(int *x,int *y, int limit);

int main() {

    srand (time(NULL));
    double start,stop, R;
    int x[size],y[size], dot, counter = 0, i;

    t = fopen("C:\\Users\\Nikita\\ClionProjects\\lab8\\t.txt","w+");

    for ( i = 0; i < size; i += 10) {

        start = clock();
        coordinates(x, y, i);
        stop = clock();
        fprintf(t, "%lf\n", (stop - start) / CLOCKS_PER_SEC);
    }

    fclose (t);

    dot = 1 + rand() % size;

    printf("Enter the radius of the circle:");
    scanf("%lf", &R);

    coordinates_x = fopen("C:\\Users\\Nikita\\ClionProjects\\lab8\\coordinates_x.txt","w+");
    coordinates_y = fopen("C:\\Users\\Nikita\\ClionProjects\\lab8\\coordinates_y.txt","w+");

    for (i = 1; i < size;i++) {
        if (pow((x[i] - x[dot]), 2) + pow((y[i] - y[dot]), 2) <= pow(R, 2)){
            fprintf(coordinates_x, "%d\n",x[i]);
            fprintf(coordinates_y, "%d\n",y[i]);
            counter++;
        }
    }

    fclose (coordinates_x);
    fclose (coordinates_y);

    printf("Amount of points - %d\n",counter);

    return 0;
}

void coordinates(int *x, int *y, int limit){
    int i;
    for(i = 0; i <= limit; i++) {
        x[i] = -5 + rand() % 10;
        y[i] = -5 + rand() % 10;
    }
}
