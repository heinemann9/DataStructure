#include <cstdio>
#include <cstdlib>

typedef struct Heap
{
    int *heap;
    int actualSize;

    Heap(int size)
    {
        heap = new int[size + 1];
        actualSize = 0;
    }
}Heap;

void InsertHeap(Heap *h, int item)
{
    h->actualSize = h->actualSize + 1;
    int i = h->actualSize;
    while ((i != 1) && (item > h->heap[i/2]))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

int DeleteHeap(Heap *h)
{
    int parent, child;
    int item, temp;
    item = h->heap[1];
    temp = h->heap[h->actualSize];
    h->actualSize = h->actualSize - 1;
    parent = 1;
    child = 2;
    while (child <= h->actualSize)
    {
        if ((temp < h->heap[child]) &&
            (h->heap[child] < h->heap[child+1]))
        {
            ++child;
        }

        if (temp >= h->heap[child])
        {
            break;
        }
        else
        {
            h->heap[parent] = h->heap[child];
            parent = child;
            child = child * 2;
        }
    }

    h->heap[parent] = temp;
    return item;
}

void printHeap(Heap *h)
{
    int i;
    printf("Heap : ");
    for (i = 1; i <= h->actualSize; ++i)
    {
        printf("[%d] ", h->heap[i]);
    }
}

int main(void)
{
    int i, n, item;
    Heap *h = new Heap(1000);
    InsertHeap(h, 10);
    InsertHeap(h, 45);
    InsertHeap(h, 19);
    InsertHeap(h, 11);
    InsertHeap(h, 96);

    printHeap(h);

    n = h->actualSize;
    for (i = 1; i <= n; ++i)
    {
        item = DeleteHeap(h);
        printf("\n delete : [%d] ", item);
    }
    printf("\n");

    return 0;
}
