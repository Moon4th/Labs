#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define size 100
FILE *file, *coordinates_x, *coordinates_y;

void coordinate(int array[3][size]);
int count(int dot,int array[3][size], int radius, int c);

int main() {

    srand (time(NULL));
    double start = clock(),stop;
    int coordinates[3][size], dot, R, counter = 0;

    coordinate(coordinates);

    dot = 1 + rand() % 99;

    printf("Enter the radius of the circle:");
    scanf("%d", &R);

    coordinates_x = fopen("C:\\Users\\Nikita\\ClionProjects\\lab8\\coordinates_x.txt","w+");
    coordinates_y = fopen("C:\\Users\\Nikita\\ClionProjects\\lab8\\coordinates_y.txt","w+");

    counter = count(dot,coordinates,R,counter);

    fclose (coordinates_x);
    fclose (coordinates_y);

    printf("Amount of points - %d\n",counter);
    stop = clock();
    printf("Lead time - %lf\n", (stop - start) / CLOCKS_PER_SEC);

    file = fopen("C:\\Users\\Nikita\\ClionProjects\\lab8\\text.txt","w+");
    fprintf(file, "%lf", (stop - start) / CLOCKS_PER_SEC);
    fclose (file);

    return 0;
}

void coordinate(int array[3][size]){
    int i;
    for(i = 1; i < size; i++) {
        array[1][i] = -5 + rand() % 10;
        array[2][i] = -5 + rand() % 10;
    }
}
int count(int dot,int array[3][size], int radius,int c){
    int i;
    for (i = 1; i < size;i++) {
       if (pow((array[1][i] - array[1][dot]), 2) + pow((array[2][i] - array[2][dot]), 2) <= pow(radius, 2)){
           fprintf(coordinates_x, "%d\n",array[1][i]);
           fprintf(coordinates_y, "%d\n",array[2][i]);
           c++;
       }
    }
    return(c);
}
