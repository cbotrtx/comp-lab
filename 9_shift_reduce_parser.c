#include <stdio.h>
#include <string.h>

char st[100], in[100];
int top = 0;

int reduce() {
    if (top >= 1 && st[top - 1] == 'i') {
        st[top - 1] = 'E';
        printf("%s\t%s\tREDUCE E->i\n", st, "");
        return 1;
    }
    if (top >= 3 && st[top - 1] == 'E' && st[top - 3] == 'E' && (st[top - 2] == '+' || st[top - 2] == '*')) {
        printf("REDUCE E->E%cE\t", st[top - 2]);
        top -= 2;
        st[top - 1] = 'E';
        st[top] = '\0';
        printf("%s\n", st);
        return 1;
    }
    if (top >= 3 && st[top - 1] == ')' && st[top - 2] == 'E' && st[top - 3] == '(') {
        top -= 2;
        st[top - 1] = 'E';
        st[top] = '\0';
        printf("REDUCE E->(E)\t%s\n", st);
        return 1;
    }
    return 0;
}

int main() {
    int i;
    printf("Grammar: E->E+E | E*E | (E) | i\n");
    printf("Enter input string: ");
    scanf("%s", in);
    printf("STACK\t\tACTION\n");
    for (i = 0; in[i] != '\0'; i++) {
        st[top++] = in[i];
        st[top] = '\0';
        printf("%s\t\tSHIFT %c\n", st, in[i]);
        while (reduce()) {
            top = strlen(st);
        }
        top = strlen(st);
    }
    if (top == 1 && st[0] == 'E')
        printf("String accepted\n");
    else
        printf("String rejected\n");
    return 0;
}
