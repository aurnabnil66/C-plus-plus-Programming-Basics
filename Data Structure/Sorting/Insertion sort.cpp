#include <iostream>
using namespace std;
int insertion_sort(int a[], int n)
{
    int i, j, item;
    for (i = 1; i < n; i++) // 5 4 3 2 1
    {
        item = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > item)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = item;
    }
    cout << "Elements after sorting : ";
    for (i = 0; i < n; i++)
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

    insertion_sort(arr, n);
}