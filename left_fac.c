#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRO 100
#define MAX_SYM 10

typedef struct {
    char nt;
    char sym[MAX_SYM];
    int sc;
} Pro;

void leftFac(Pro* pro, int np, char nt) {
    int i, j, k;
    for (i = 0; i < np; i++) {
        if (pro[i].nt == nt) {
            int cpl = 1;
            for (j = i + 1; j < np; j++) {
                if (pro[j].nt == nt) {
                    int pl = 0;
                    while (pl < pro[i].sc && pl < pro[j].sc && pro[i].sym[pl] == pro[j].sym[pl]) {
                        pl++;
                    }
                    if (pl > cpl) {
                        cpl = pl;
                    }
                }
            }
            if (cpl > 1) {
                printf("Left factoring applied for %c -> ", nt);
                for (k = 0; k < cpl; k++) {
                    printf("%c", pro[i].sym[k]);
                }
                printf("\nNew productions:\n");
                char nnt = 'A' + np;
                printf("%c -> ", nt);
                for (k = cpl; k < pro[i].sc; k++) {
                    printf("%c", pro[i].sym[k]);
                }
                printf("%c'\n", nnt);
                printf("%c' -> ", nnt);
                for (j = i + 1; j < np; j++) {
                    if (pro[j].nt == nt) {
                        for (k = cpl; k < pro[j].sc; k++) {
                            printf("%c", pro[j].sym[k]);
                        }
                        printf("%c' | ", nnt);
                    }
                }
                printf("epsilon\n");
                return;
            }
        }
    }
    printf("No left factoring applicable for %c\n", nt);
}

int main() {
    int np;
    char nt;
    Pro pro[MAX_PRO];

    printf("Enter the number of productions: ");
    scanf("%d", &np);

    printf("Enter the productions:\n");
    for (int i = 0; i < np; i++) {
        scanf(" %c", &pro[i].nt);
        char sym;
        pro[i].sc = 0;
        while (scanf(" %c", &sym) == 1 && sym != '|') {
            pro[i].sym[pro[i].sc++] = sym;
        }
    }

    printf("Enter the non-terminal to perform left factoring for: ");
    scanf(" %c", &nt);

    leftFac(pro, np, nt);

    return 0;
}
