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

int main(int argc, char *argv[]) {
    FILE *fp;
    int c, n;
    char buf[100];
    if (argc < 2) {
        printf("Usage: %s inputfile\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file\n");
        return 1;
    }
    c = fgetc(fp);
    while (c != EOF) {
        if (isspace(c)) {
            c = fgetc(fp);
        } else if (isalpha(c) || c == '_') {
            n = 0;
            while ((isalnum(c) || c == '_') && n < 99) {
                buf[n++] = c;
                c = fgetc(fp);
            }
            buf[n] = 0;
            printf("%-15s %s\n", buf, isKeyword(buf) ? "KEYWORD" : "IDENTIFIER");
        } else if (isdigit(c)) {
            n = 0;
            while ((isdigit(c) || c == '.') && n < 99) {
                buf[n++] = c;
                c = fgetc(fp);
            }
            buf[n] = 0;
            printf("%-15s NUMBER\n", buf);
        } else if (c == '"') {
            n = 0;
            buf[n++] = c;
            c = fgetc(fp);
            while (c != '"' && c != EOF && n < 98) {
                buf[n++] = c;
                c = fgetc(fp);
            }
            buf[n++] = '"';
            buf[n] = 0;
            c = fgetc(fp);
            printf("%-15s STRING\n", buf);
        } else if (strchr("+-*/%=<>!&|", c)) {
            n = 0;
            buf[n++] = c;
            c = fgetc(fp);
            if (strchr("=+-&|", c) && c != EOF) {
                buf[n++] = c;
                c = fgetc(fp);
            }
            buf[n] = 0;
            printf("%-15s OPERATOR\n", buf);
        } else {
            printf("%-15c SEPARATOR\n", c);
            c = fgetc(fp);
        }
    }
    fclose(fp);
    return 0;
}
