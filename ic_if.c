#include <stdio.h>
#include <string.h>

#define MAX 100

void genIC(char *cond, char *tp, char *fp) {
    static int lblCnt = 0;
    int lbl1 = lblCnt++;
    int lbl2 = lblCnt++;

    printf("if %s goto L%d\n", cond, lbl1);
    printf("%s\n", fp);
    printf("goto L%d\n", lbl2);
    printf("L%d: %s\n", lbl1, tp);
    printf("L%d:\n", lbl2);
}

int main() {
    char cond[MAX], tp[MAX], fp[MAX];

    printf("Enter the condition of the if statement: ");
    fgets(cond, MAX, stdin);
    cond[strcspn(cond, "\n")] = '\0';  // Remove newline character

    printf("Enter the true part of the if statement: ");
    fgets(tp, MAX, stdin);
    tp[strcspn(tp, "\n")] = '\0';  // Remove newline character

    printf("Enter the false part of the if statement: ");
    fgets(fp, MAX, stdin);
    fp[strcspn(fp, "\n")] = '\0';  // Remove newline character

    printf("\nIntermediate Code:\n");
    genIC(cond, tp, fp);

    return 0;
}
