#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
void quick_sort(int a[], int f, int l)
{
    if (f < l)                       //   51 95 66 72 42 38 39 41 15
    {
        int x;
        int i = f + 1, j = l;
        while (i < j)
        {
            while (a[i] <= a[f])
            {
                i++;
            }
            while (a[j] >= a[f])
            {
                j--;
            }
            if (i < j)
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
        
        x = a[j];
        a[j] = a[f];
        a[f] = x;

        quick_sort(a, f, j - 1);
        quick_sort(a, j + 1, l);
    }
}
int main()
{
    int arr[100];
    int n, i;
    cout << "Enter number of elements : ";
    cin >> n;
    int first = 0, last = n - 1;
    cout << "Enter array elements : " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Element - " << i + 1 << " = ";
        cin >> arr[i];
    }
    quick_sort(arr, first, last);

    cout << "After sorting : ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}