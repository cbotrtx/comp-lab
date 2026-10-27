#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][20];
int n;
int first[128][128], follow[128][128];

int add(int set[][128], int a, int b) {
    if (set[a][b]) return 0;
    set[a][b] = 1;
    return 1;
}

int main() {
    int i, j, k, changed, flag;
    char A, X, B;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions as A=XYZ (uppercase = non-terminal, # = epsilon):\n");
    for (i = 0; i < n; i++) scanf("%s", prod[i]);

    do {
        changed = 0;
        for (i = 0; i < n; i++) {
            A = prod[i][0];
            flag = 1;
            for (j = 2; prod[i][j] != '\0'; j++) {
                X = prod[i][j];
                if (!isupper(X)) {
                    changed |= add(first, A, X);
                    flag = 0;
                    break;
                }
                for (k = 0; k < 128; k++)
                    if (first[X][k] && k != '#') changed |= add(first, A, k);
                if (!first[X]['#']) {
                    flag = 0;
                    break;
                }
            }
            if (flag) changed |= add(first, A, '#');
        }
    } while (changed);

    add(follow, prod[0][0], '$');
    do {
        changed = 0;
        for (i = 0; i < n; i++) {
            A = prod[i][0];
            for (j = 2; prod[i][j] != '\0'; j++) {
                B = prod[i][j];
                if (!isupper(B)) continue;
                flag = 1;
                for (k = j + 1; prod[i][k] != '\0'; k++) {
                    X = prod[i][k];
                    if (X == '#') break;
                    if (!isupper(X)) {
                        changed |= add(follow, B, X);
                        flag = 0;
                        break;
                    }
                    for (int m = 0; m < 128; m++)
                        if (first[X][m] && m != '#') changed |= add(follow, B, m);
                    if (!first[X]['#']) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (int m = 0; m < 128; m++)
                        if (follow[A][m]) changed |= add(follow, B, m);
                }
            }
        }
    } while (changed);

    for (i = 0; i < n; i++) {
        A = prod[i][0];
        int seen = 0;
        for (j = 0; j < i; j++) if (prod[j][0] == A) seen = 1;
        if (seen) continue;
        printf("FIRST(%c) = { ", A);
        for (k = 0; k < 128; k++) if (first[(int)A][k]) printf("%c ", k);
        printf("}\n");
    }
    for (i = 0; i < n; i++) {
        A = prod[i][0];
        int seen = 0;
        for (j = 0; j < i; j++) if (prod[j][0] == A) seen = 1;
        if (seen) continue;
        printf("FOLLOW(%c) = { ", A);
        for (k = 0; k < 128; k++) if (follow[(int)A][k]) printf("%c ", k);
        printf("}\n");
    }
    return 0;
}
