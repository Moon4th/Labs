#include <stdio.h>
#include <stdlib.h>

typedef struct type_node //Односвязный список
{
    int data;
    struct type_node *next;
} node;

int main(int argc, char* argv[])
{
    node *spis , *tmp, *first, *prev = NULL;
    int n, i, a;
    char timeout;
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    for (i=0; i < n; i++)
    {
        spis = malloc(sizeof(node));
        printf("Enter %d list item: ", i);
        scanf("%d", &a);
        spis->data = a;
        if (i == 0) {
            first = spis;
            prev = first;
        }else
        {
            prev->next = spis;
            prev = prev->next;
        }
    }
    //spis последний элемент списка
    spis->next = NULL;
    //присвоение первом элементу
    spis = first;
    printf("list items: ");
    while(spis != NULL)
    {
        printf("%d ", spis->data);
        spis = spis->next;
    }
    printf("\r\n");
    return 0;
}