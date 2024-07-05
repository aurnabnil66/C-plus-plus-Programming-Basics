#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void max_heapify(int heap[], int heap_size, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest, x;

    if (l <= heap_size && heap[l] > heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        x = heap[i];
        heap[i] = heap[largest];
        heap[largest] = x;
        max_heapify(heap, heap_size, largest);
    }
}

void build_max_heap(int heap[], int heap_size)
{
    for (int i = heap_size / 2; i > 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

void print_heap(int heap[], int heap_size)
{
    for (int i = 1; i <= heap_size; i++)
    {
        cout << heap[i] << "   ";
    }
    cout << endl
         << endl;
}

int main()
{
    int heap_size = 9;
    int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};

    cout << "Before : \n";
    print_heap(heap, heap_size);

    build_max_heap(heap, heap_size);

    max_heapify(heap, heap_size, 3);

    cout << "After : \n";
    print_heap(heap, heap_size);
}