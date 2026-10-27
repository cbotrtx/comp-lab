#include <stdio.h>
#include <ctype.h>

int main() {
    char s[200];
    int i, v = 0, c = 0;
    char ch;
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    for (i = 0; s[i] != '\0'; i++) {
        ch = tolower(s[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            v++;
        else if (isalpha(ch))
            c++;
    }
    printf("Vowels = %d\nConsonants = %d\n", v, c);
    return 0;
}
