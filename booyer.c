#include<stdio.h>
#include<string.h> 
#include<conio.h>

int last[100];

main() {
    void bmtable(char[], char[]);
    int bmsearch(char[], char[]);
    int min(int, int);
    char t[100], p[20];
    int pos;
    printf("enter text\n");
    scanf("%s", t);
    printf("enter pattern\n");
    scanf("%s", p);
    bmtable(t, p);
    pos = bmsearch(t, p);
    if (pos == -1) printf("not found\n"); else printf("found at pos %d\n", pos + 1);
    getch();
}

void bmtable(char t[100], char p[20]) {
    int i = 0, j, m, n, l, k = -1;
    n = strlen(t);
    m = strlen(p);
    while (i < n) {
        j = m - 1;
        l = i - 1;
        while (l > -1 && t[i] != t[l])l--;
        if (l == -1) {
            while (j > -1 && p[j] != t[i])j--;
            {
                last[++k] = j;
            }
        }
        i++;
    }
    for (j = 0; j <= k; j++) printf("%d\t", last[j]);
    printf("\n");
}


int bmsearch(char t[100], char p[20]) {
    int i, j, m, n;
    n = strlen(t);
    m = strlen(p);
    i = m - 1;
    j = m - 1;
    while (i < n) {
        if (p[j] == t[i]) if (j == 0)return i; else {
            i--;
            j--;
        }
        else {
            i = i + m - min(j, 1 + last[t[i]]);
            j = m - 1;
        }
    }
    return -1;
}

int min(int i, int j) {
    if (i < j)return i;
    return j;
}

