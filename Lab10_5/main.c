#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;

    printf("Введите количество товаров: ");
    scanf("%i", &n);

    struct storage{
        char name[10];
        double weight;
        int price;
    };
    struct storage* data = (struct storage*)malloc(sizeof(struct storage) * n);

    for(i = 0; i < n; i++)
    {
        printf("Введите название товара:\n");
        scanf("%s", &data[i].name);

        printf("Введите вес товара:\n");
        scanf("%lf", &data[i].weight);

        printf("Введите цену товара:\n");
        scanf("%d", &data[i].price);
    }

    for(int i = 0; i < n; i++)
    {
        printf("Название: %s Вес: %lf Цена: %d\n", data[i].name, data[i].weight, data[i].price);
    }

    free(data);

    return 0;
}