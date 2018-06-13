#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int amount, i;
    struct car {
        char color;
        double weight;
        double price;
        double max_speed;
    };

    printf("How many cars?\n");
    scanf("%d", &amount);

    struct car* cars = (struct car*)malloc(sizeof(struct car) * amount);

    for (i = 1; i <= amount; i++){
        printf("%d car:\n", i);
        printf("Enter price:\n$");
        scanf("%lf",&cars[i].price);
        printf("Enter color:\n");
        scanf("%s",&cars[i].color);
        printf("Enter weight:\n");
        scanf("%lf",&cars[i].weight);
        printf("Enter max speed:\n");
        scanf("%lf",&cars[i].max_speed);
    }

    for (i = 1; i <= amount; i++){
        printf("\nInformation about %d car\n", i);
        printf("Price - %lf\n", cars[i].price);
        printf("Color - %s\n", &cars[i].color);
        printf("Weight - %lf\n", cars[i].weight);
        printf("Max speed - %lf\n", cars[i].max_speed);
    }

    free(cars);
    return 0;
}