#include<stdio.h>
#include<string.h>
#include<process.h>

struct hashtuple {
    int key;
    char data;
} table[10];
int divisor = 10, size = 10;

int search(int key) {
    int i = key % divisor;
    int j = i;
    do {
        if (table[j].data == 0 || table[j].key)
            return j;
        j = (j + 1) % divisor;
    } while (j != i);
    return j;
}

int find(int key) {
    int b = search(key);
    if (table[b].data == 0 || table[b].key != key)
        return 0;
    else
        return table[b].data;
}

void insert(struct hashtuple ht) {
    int b = search(ht.key);
    if (table[b].data == 0) {
        table[b] = ht;
        size++;
    }
    else {
        if (table[b].key == ht.key)
            table[b].data = ht.data;
        else
            printf("hash table is FULL");
    }
}

void display() {
    int i;
    for (i = 0; i < divisor; i++) {
        if (table[i].data == 0)
            printf("NULL\n");
        else {
            printf("%d", table[i].key);
            printf("%d\n", table[i].data);
        }
    }
}

int Size() {
    return size;
}

void main() {
    struct hashtuple table[11], t;
    int i, ch, k;
    for (i = 0; i < divisor; i++)
        table[i].data = 0;
    do {
        printf("\n1.insertion\n2.find\n3.size\n4.display\n5.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the key value:");
                scanf("%d", &t.key);
                printf("Enter the data value:");
                scanf("%d", &t.data);
                insert(t);
                break;
            case 2:
                printf("Enter search key:");
                scanf("%d", &k);
                printf("The associated with %d is %d", k, find(k));
                break;
            case 3:
                printf("the size of hash table %d", Size());
                break;
            case 4:
                printf("The hash table is \n");
                display();
                break;
            case 5:
                exit(0);
        }
    } while (1);
}

