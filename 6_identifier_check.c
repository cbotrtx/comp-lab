#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100];
    int i, valid = 1;
    printf("Enter a string: ");
    scanf("%s", s);
    if (!isalpha(s[0])) valid = 0;
    for (i = 1; s[i] != '\0' && valid; i++)
        if (!isalnum(s[i])) valid = 0;
    if (valid)
        printf("Valid identifier\n");
    else
        printf("Invalid identifier\n");
    return 0;
}
