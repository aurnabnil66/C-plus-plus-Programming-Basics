#include <iostream>
using namespace std;
int binary_search(int a[], int n, int x)
{
    int left, right;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[100];
    int n, i, x;
    cout << "Enter number of elements for the array : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Element - " << i + 1 << " = ";
        cin >> arr[i];
    }
    cout << "Enter searching element : ";
    cin >> x;

    int result = binary_search(arr, n, x);
    if (result == -1)
    {
        cout << "Element not found!";
    }
    else
    {
        cout << "Element found at index " << result;
    }
}