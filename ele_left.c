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

void elimLR(Pro* pro, int np, char nt) {
    int i, j, k;
    for (i = 0; i < np; i++) {
        if (pro[i].nt == nt) {
            for (j = 0; j < i; j++) {
                char nnt = 'A' + np;
                Pro npro;
                npro.nt = nnt;
                npro.sc = pro[j].sc + 1;
                npro.sym[0] = pro[i].sym[0];
                for (k = 1; k < npro.sc; k++) {
                    npro.sym[k] = pro[j].sym[k - 1];
                }
                pro[np++] = npro;
            }
            break;
        }
    }
    printf("Productions after eliminating left recursion:\n");
    for (i = 0; i < np; i++) {
        if (pro[i].nt != nt) {
            printf("%c -> ", pro[i].nt);
            for (j = 0; j < pro[i].sc; j++) {
                printf("%c", pro[i].sym[j]);
            }
            printf("\n");
        }
    }
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

    printf("Enter the non-terminal to eliminate left recursion for: ");
    scanf(" %c", &nt);

    elimLR(pro, np, nt);

    return 0;
}
