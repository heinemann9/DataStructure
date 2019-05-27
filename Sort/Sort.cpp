#include <iostream>

void selectionSort(int list[], int n)
{
    int least, i, j, temp;
    for (i = 0; i < n - 1; ++i)
    {
        least = i;
        for (j = i + 1; j < n; ++j)
        {
            if (list[least] > list[j])
            {
                least = j;
            }
        }

        temp = list[i];
        list[i] = list[least];
        list[least] = temp;
    }
}

void insertionSort(int list[], int n)
{
    int key, i, j, temp;
    for (i = 1; i < n; ++i)
    {
        key = list[i];
        for (j = n -1; j >= 0 && list[j] > key; --j)
        {
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}

void bubbleSort(int list[], int n)
{
    int i, j, temp;
    for (i = n -1; i >= 0; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}