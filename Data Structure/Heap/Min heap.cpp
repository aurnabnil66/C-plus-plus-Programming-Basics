#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void min_heapify(int heap[], int heap_size, int i)
{
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    int x;

    if (l <= heap_size && heap[l] < heap[smallest])
    {
        smallest = l;
    }
    if (r <= heap_size && heap[r] < heap[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        x = heap[smallest];
        heap[smallest] = heap[i];
        heap[i] = x;
        min_heapify(heap, heap_size, smallest);
    }
}

void build_min_heap(int heap[], int heap_size)
{
    for (int i = heap_size / 2; i >= 1; i--)
    {
        min_heapify(heap, heap_size, i);
    }
}

void print_heap(int heap[], int heap_size)
{
    for (int i = heap_size; i >= 1; i--)
    {
        cout << heap[i] << "   ";
    }
    cout << endl
         << endl;
}

int main()
{
    int heap_size = 9;
    int heap[] = {0, 40, 32, 60, 22, 70, 38, 85, 60, 55};

    build_min_heap(heap, heap_size);
    
    print_heap(heap, heap_size);
}