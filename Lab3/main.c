#include <stdio.h>
#include <string.h>
#define size 64

int main() {

    int i, q;
    char sequence[size] = {0}, result[size] = {0}, buffer[size] = {0}, vowels[] = {'A', 'a', 'E', 'e', 'Y', 'y', 'I', 'i', 'U', 'u', 'O', 'o'};

    printf("Enter the sequence:\n");
    scanf("%s", sequence);

    for (i = 0; i <= strlen(sequence); i++){
        for(q = 0; q < strlen(vowels); q++){
            if (sequence[i] == vowels[q]){
                sprintf(buffer, "%c", sequence[i]);
                strcat(result, buffer);
            }
        }
    }

    printf("Vowels - %s", result);
    return 0;
}