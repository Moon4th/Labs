#include <stdio.h>
#include <string.h>

char* allVowels(char* source, char* result) {
    static const char CVowels[] = "EYUIOAeyuioa";
    char* pstr = result;

    for (; *source; ++source) {
        if (strchr(CVowels, *source)) {
            *pstr++ = *source;
        }
    }
    *pstr = 0;

    return result;
}

int main() {
    char source[256], result[256];

    printf("text: ");
    fgets(source, sizeof(source), stdin);

    printf("vowels: %s\n", allVowels(source, result));

    return 0;
}