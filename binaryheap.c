#include<stdio.h> 
int size=-1; 
main()
{
void heapins(int [], int);
void heapdel(int []);
int n, heap[100], i, ele;
printf("enter no of elements\n"); scanf("%d",&n); printf("enter the elelments\n"); for(
i = 0;
i<n;
i++)
{
scanf("%d",&ele);
heapins(heap, ele
);
}
for(
i = 1;
i<n;
i++)
heapdel(heap);
printf("the sorted or deleted elements list are:\n"); for(
i = 0;
i<n;
i++) printf("%d\t",heap[i]);

getch();

}

void heapins(int heap[100], int ele) {
    int cur;
    cur = ++size;
    while (cur != 0 && ele > heap[(cur - 1) / 2]) {
        heap[cur] = heap[(cur - 1) / 2];
        cur = (cur - 1) / 2;
    }
    heap[cur] = ele;
}

void heapdel(int heap[100]) {
    int lastele, cur, child;
    lastele = heap[size];
    size--;
    cur = 0;
    child = 1;
    heap[size + 1] = heap[0];
    while (child <= size) {
        if (child < size && heap[child] < heap[child + 1]) child++;
        if (lastele > heap[child]) break;
        heap[cur] = heap[child];
        cur = child;
        child = 2 * cur + 1;
    }
    heap[cur] = lastele;
} 

