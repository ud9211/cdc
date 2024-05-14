#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct St {
    int tr[2];
    bool ac;
} St;

typedef struct NFA {
    St st[MAX];
    int ini;
    int num;
} NFA;

St creSt() {
    St st;
    st.tr[0] = -1;
    st.tr[1] = -1;
    st.ac = false;
    return st;
}

void iniNFA(NFA *nfa) {
    nfa->ini = 0;
    nfa->num = 1;
    nfa->st[0] = creSt();
}

void addTr(NFA *nfa, int frm, int to, char in) {
    if (in == '0') {
        nfa->st[frm].tr[0] = to;
    } else if (in == '1') {
        nfa->st[frm].tr[1] = to;
    }
}

void setAc(NFA *nfa, int idx) {
    nfa->st[idx].ac = true;
}

NFA conNFA(NFA nfa1, NFA nfa2) {
    NFA res;
    iniNFA(&res);
    memcpy(res.st, nfa1.st, sizeof(St) * nfa1.num);
    res.num = nfa1.num;
    for (int i = 0; i < nfa1.num; i++) {
        if (nfa1.st[i].ac) {
            addTr(&res, i, res.num, '0');
        }
    }
    for (int i = 0; i < nfa2.num; i++) {
        res.st[res.num + i] = nfa2.st[i];
    }
    res.num += nfa2.num;
    return res;
}

NFA uniNFA(NFA nfa1, NFA nfa2) {
    NFA res;
    iniNFA(&res);
    int newIni = res.num;
    res.st[newIni] = creSt();
    res.num++;
    addTr(&res, newIni, nfa1.ini, '0');
    addTr(&res, newIni, nfa2.ini, '0');
    for (int i = 0; i < nfa1.num; i++) {
        res.st[res.num + i] = nfa1.st[i];
    }
    res.num += nfa1.num;
    for (int i = 0; i < nfa2.num; i++) {
        res.st[res.num + i] = nfa2.st[i];
    }
    res.num += nfa2.num;
    return res;
}

void disNFA(NFA nfa) {
    printf("Initial State: %d\n", nfa.ini);
    printf("Accepting States: ");
    for (int i = 0; i < nfa.num; i++) {
        if (nfa.st[i].ac) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("Transitions:\n");
    for (int i = 0; i < nfa.num; i++) {
        printf("State %d:\n", i);
        printf("  On 0: %d\n", nfa.st[i].tr[0]);
        printf("  On 1: %d\n", nfa.st[i].tr[1]);
    }
}

int main() {
    NFA nfa1, nfa2, res;
    iniNFA(&nfa1);
    iniNFA(&nfa2);
    setAc(&nfa1, 0);
    addTr(&nfa1, 0, 0, '0');
    addTr(&nfa1, 0, 0, '1');
    setAc(&nfa2, 1);
    addTr(&nfa2, 0, 1, '0');
    res = uniNFA(nfa1, nfa2);
    disNFA(res);
    return 0;
}
