#include <stdio.h>

void follow(char c) {
    int i, j;
    if (production[0][0] == c) {
        followSet[n++] = '$';
    }

    for (i = 0; i < 10; i++) {
        for (j = 2; j < 10; j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0') {
                    findFirst(production[i][j + 1], i, (j + 2));
                }
                if (production[i][j + 1] == '\0' && c != production[i][0]) {
                    follow(production[i][0]);
                }
            }
        }
    }
}

void findFirst(char c, int q1, int q2) {
    int j;
    if (!(isupper(c))) {
        firstSet[m++] = c;
    }
    for (j = 0; j < 10; j++) {
        if (production[j][0] == c) {
            if (production[j][2] == '#') {
                if (production[q1][q2] == '\0') {
                    firstSet[m++] = '#';
                } else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                    findFirst(production[q1][q2], q1, (q2 + 1));
                } else {
                    firstSet[m++] = '#';
                }
            } else if (!isupper(production[j][2])) {
                firstSet[m++] = production[j][2];
            } else {
                findFirst(production[j][2], j, 3);
            }
        }
    }
}

int main() {
    int i, z;
    char c, ch;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the productions: ");
        scanf("%s", production[i]);
    }
    do {
        m = 0;
        printf("Enter the element whose first is to be found: ");
        scanf(" %c", &c);
        findFirst(c, 0, 0);
        printf("First(%c) = { ", c);
        for (i = 0; i < m; i++) {
            printf("%c ", firstSet[i]);
        }
        printf("}\n");

        printf("Enter the element whose follow is to be found: ");
        scanf(" %c", &c);
        n = 0;
        follow(c);
        printf("Follow(%c) = { ", c);
        for (i = 0; i < n; i++) {
            printf("%c ", followSet[i]);
        }
        printf("}\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
