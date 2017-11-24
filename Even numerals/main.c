#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define str 256

int main() {
    int counter = 0, number;
    char s_number[str];
   printf("Enter the number:");
            scanf("%s",s_number);
            while (strstr(s_number,".")){
                printf ("Enter integer value:\n");
                scanf ("%s",s_number);
            }
            number = atoi(s_number);
            while (number != 0){
                if (number % 2 == 0){
                    counter++;
                    number = number / 10;
                }
                else{
                    number = number / 10;
                }
            }
            printf ("Amount of even numbers:%d\n",counter);
    return 0;
}