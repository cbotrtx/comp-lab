#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *s) {
    char *k[] = {"int","float","char","double","if","else","while","for","return","void","do","break","continue","switch","case","long","short"};
    int i;
    for (i = 0; i < 17; i++)
        if (strcmp(s, k[i]) == 0) return 1;
    return 0;
}

int main() {
    int c, n;
    char buf[100];
    printf("Enter the program text (Ctrl+D to end):\n");
    c = getchar();
    while (c != EOF) {
        if (isspace(c)) {
            c = getchar();
        } else if (isalpha(c) || c == '_') {
            n = 0;
            while ((isalnum(c) || c == '_') && n < 99) {
                buf[n++] = c;
                c = getchar();
            }
            buf[n] = 0;
            printf("%s\t%s\n", buf, isKeyword(buf) ? "Keyword" : "Identifier");
        } else if (isdigit(c)) {
            n = 0;
            while ((isdigit(c) || c == '.') && n < 99) {
                buf[n++] = c;
                c = getchar();
            }
            buf[n] = 0;
            printf("%s\tNumber\n", buf);
        } else if (strchr("+-*/%=<>!&|", c)) {
            printf("%c\tOperator\n", c);
            c = getchar();
        } else {
            printf("%c\tSpecial Symbol\n", c);
            c = getchar();
        }
    }
    return 0;
}
