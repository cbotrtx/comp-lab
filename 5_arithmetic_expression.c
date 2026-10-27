#include <stdio.h>
#include <ctype.h>

char s[100];
int pos = 0, err = 0;

void E();

void F() {
    if (s[pos] == '(') {
        pos++;
        E();
        if (s[pos] == ')') pos++;
        else err = 1;
    } else if (isalnum(s[pos])) {
        while (isalnum(s[pos])) pos++;
    } else {
        err = 1;
    }
}

void T() {
    F();
    while (!err && (s[pos] == '*' || s[pos] == '/')) {
        pos++;
        F();
    }
}

void E() {
    T();
    while (!err && (s[pos] == '+' || s[pos] == '-')) {
        pos++;
        T();
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", s);
    E();
    if (!err && s[pos] == '\0')
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
    return 0;
}
