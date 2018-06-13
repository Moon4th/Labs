#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int size = 0, i;
    int *values = NULL, *square_values = NULL;

    printf("Enter the size of the array:");
    scanf("%d",&size);
    values = (int*)malloc(size * sizeof(int));
    square_values = (int*)malloc(size * sizeof(int));

    for (i = 0;i<size;i++){
        values[i] = 1 + rand() % 100;
    }

    for (i = 0;i<size;i++){
        printf("%d | ", values[i]);
        square_values[i] = values[i] * values[i];
        printf("%d\n", square_values[i]);
    }

    free(values);
    free(square_values);

    return 0;
}