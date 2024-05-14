#include <stdio.h>
#include <string.h>

#define MAX 100

void genIC(char *cond, char *bd) {
    static int lblCnt = 0;
    int lbl1 = lblCnt++;
    int lbl2 = lblCnt++;

    printf("L%d:\n", lbl1);
    printf("if %s goto L%d\n", cond, lbl2);
    printf("goto L%d\n", lbl2 + 1);
    printf("L%d: %s\n", lbl2, bd);
    printf("goto L%d\n", lbl1);
    printf("L%d:\n", lbl2 + 1);
}

int main() {
    char cond[MAX], bd[MAX];

    printf("Enter the condition of the while statement: ");
    fgets(cond, MAX, stdin);
    cond[strcspn(cond, "\n")] = '\0';  // Remove newline character

    printf("Enter the body of the while statement: ");
    fgets(bd, MAX, stdin);
    bd[strcspn(bd, "\n")] = '\0';  // Remove newline character

    printf("\nIntermediate Code:\n");
    genIC(cond, bd);

    return 0;
}
