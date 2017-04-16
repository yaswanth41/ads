#include<stdio.h>
#include<string.h>
#include<conio.h>

int next[100];

main() {
    void kmptable(char[]);
    int kmpsearch(char[], char[]);
    char t[100], p[20];
    int pos;
    printf("enter text\n");
    scanf("%s", t);
    printf("enter pattern\n");
    scanf("%s", p);

    kmptable(p);
    pos = kmpsearch(t, p);
    if (pos == -1) printf("not found\n"); else printf("found at pos %d\n", pos + 1);
    getch();
}

void kmptable(char p[20]) {
    int i, j, m, n;
    i = 0;
    j = next[0] = -1;

    m = strlen(p);
    while (i < m) {
        while (j > -1 && p[j] != p[i])j = next[j];
        next[++i] = ++j;
    }
}

int kmpsearch(char t[100], char p[20]) {
    int i = 0, j = 0, m, n;
    n = strlen(t);
    m = strlen(p);
    while (i <= n) {
        while (j > -1 && p[j] != t[i])j = next[j];
        i++;
        j++;
        if (j == m) return i - j;
    }
    return -1;
} 
