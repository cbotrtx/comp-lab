#include <stdio.h>
#include <string.h>

char s[100];
int pos = 0, err = 0;

void E();
void EP();
void T();
void TP();
void F();

void E() {
    T();
    EP();
}

void EP() {
    if (s[pos] == '+') {
        pos++;
        T();
        EP();
    }
}

void T() {
    F();
    TP();
}

void TP() {
    if (s[pos] == '*') {
        pos++;
        F();
        TP();
    }
}

void F() {
    if (s[pos] == '(') {
        pos++;
        E();
        if (s[pos] == ')') pos++;
        else err = 1;
    } else if (s[pos] == 'i') {
        pos++;
    } else {
        err = 1;
    }
}

int main() {
    printf("Grammar: E->TE'  E'->+TE'|e  T->FT'  T'->*FT'|e  F->(E)|i\n");
    printf("Enter input string (i for id): ");
    scanf("%s", s);
    E();
    if (!err && s[pos] == '\0')
        printf("String accepted\n");
    else
        printf("String rejected\n");
    return 0;
}
