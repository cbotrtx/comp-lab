#include <stdio.h>
#include <ctype.h>

int main() {
    int c, lines = 0, words = 0, chars = 0, inword = 0;
    printf("Enter text (Ctrl+D to end):\n");
    while ((c = getchar()) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            inword = 0;
        } else if (!inword) {
            inword = 1;
            words++;
        }
    }
    printf("Lines = %d\nWords = %d\nCharacters = %d\n", lines, words, chars);
    return 0;
}
