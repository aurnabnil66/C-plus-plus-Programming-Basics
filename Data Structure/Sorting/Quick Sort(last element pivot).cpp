#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void quick_sort(int a[], int f, int l)
{
    int i = f, j = l - 1, pivot = l;

    if(f < l)
    {
        while(i <= j)
        {
            while(a[i] < a[pivot])  //*****
            {
                i++;
            }
            while(j >= f && a[j] >= a[pivot])
            {
                j--;
            }
            if(i <= j)
            {
                int x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
        int temp = a[i];
        a[i] = a[pivot];
        a[pivot] = temp;

        quick_sort(a, f, i - 1);
        quick_sort(a, i + 1, l);
    }
}

int main()
{
    int A[10];
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int first = 0, last = n - 1;
    cout << "Enter elements : " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Element - " << i + 1 << " = ";
        cin >> A[i];
    }

    quick_sort(A, first, last);

    cout << "After sorting : " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
