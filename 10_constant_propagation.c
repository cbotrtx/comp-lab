#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char name[50][20];
int val[50];
int cnt = 0;

int find(char *s) {
    int i;
    for (i = 0; i < cnt; i++)
        if (strcmp(name[i], s) == 0) return i;
    return -1;
}

int isnum(char *s) {
    return isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]));
}

void forget(char *s) {
    int i = find(s);
    if (i >= 0) {
        strcpy(name[i], name[cnt - 1]);
        val[i] = val[cnt - 1];
        cnt--;
    }
}

void setval(char *s, int v) {
    int i = find(s);
    if (i < 0) {
        i = cnt++;
        strcpy(name[i], s);
    }
    val[i] = v;
}

int main() {
    int n, i, r, x, y, k;
    char line[100], lhs[20], a[20], b[20], op;
    printf("Enter number of statements: ");
    scanf("%d", &n);
    getchar();
    printf("Enter statements like  x = 5  or  y = x + 2:\n");
    for (i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        r = sscanf(line, "%s = %s %c %s", lhs, a, &op, b);
        if (r == 2) {
            if (!isnum(a) && (k = find(a)) >= 0) sprintf(a, "%d", val[k]);
            if (isnum(a)) {
                setval(lhs, atoi(a));
                printf("%s = %s\n", lhs, a);
            } else {
                forget(lhs);
                printf("%s = %s\n", lhs, a);
            }
        } else if (r == 4) {
            if (!isnum(a) && (k = find(a)) >= 0) sprintf(a, "%d", val[k]);
            if (!isnum(b) && (k = find(b)) >= 0) sprintf(b, "%d", val[k]);
            if (isnum(a) && isnum(b)) {
                x = atoi(a);
                y = atoi(b);
                if (op == '+') k = x + y;
                else if (op == '-') k = x - y;
                else if (op == '*') k = x * y;
                else k = y ? x / y : 0;
                setval(lhs, k);
                printf("%s = %d\n", lhs, k);
            } else {
                forget(lhs);
                printf("%s = %s %c %s\n", lhs, a, op, b);
            }
        }
    }
    return 0;
}
