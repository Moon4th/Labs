#include <stdio.h>
#include <malloc.h>

int main()
{
    int *a;
    int i;
    a = (int*)malloc(10 * sizeof(int));
    for (i = 0; i <= 20; i++)
        printf("%d %d\n", i, i*i);
    free(a);
    return 0;
}