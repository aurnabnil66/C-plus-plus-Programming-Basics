#include <iostream>
using namespace std;
void selection_sort(int a[], int n)
{
    int i, j, x;
    for (i = 0; i < n - 1; i++)
    {
        int ind_min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[ind_min] > a[j])
            {
                ind_min = j;
            }
        }
        if (ind_min != i)
        {
            x = a[i];
            a[i] = a[ind_min];
            a[ind_min] = x;
        }
    }
    cout << "After sorting : ";
    for ( i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}

int main()
{
    int arr[100];
    int n, i;
    cout << "Enter number of elements for the array : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Element - " << i + 1 << " = ";
        cin >> arr[i];
    }
    selection_sort(arr, n);
}
