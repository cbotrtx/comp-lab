#include <stdio.h>

int main() {
    int n, i, r;
    char line[100], lhs[20], a[20], b[20], op;
    char *ins;
    printf("Enter number of three address statements: ");
    scanf("%d", &n);
    getchar();
    printf("Enter statements like  t1 = a + b  or  x = t1:\n");
    for (i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        r = sscanf(line, "%s = %s %c %s", lhs, a, &op, b);
        printf("MOV R0, %s\n", a);
        if (r == 4) {
            if (op == '+') ins = "ADD";
            else if (op == '-') ins = "SUB";
            else if (op == '*') ins = "MUL";
            else ins = "DIV";
            printf("%s R0, %s\n", ins, b);
        }
        printf("MOV %s, R0\n", lhs);
    }
    return 0;
}
