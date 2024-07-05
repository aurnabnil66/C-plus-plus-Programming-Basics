#include <iostream>
using namespace std;
void merge(int A[], int left, int mid, int right)
{
    int i;
    int index_a, index_l, index_r;
    int size_left, size_right;

    size_left = mid - left + 1;
    size_right = right - mid;

    int L[size_left], R[size_right];

    /***************************** Copying Elements from main Array to L & R array *****************************/

    for (i = 0; i < size_left; i++)
    {
        L[i] = A[left + i];
    }
    for (i = 0; i < size_right; i++)
    {
        R[i] = A[mid + 1 + i];
    }

    /***************************** Comparing elements and inserting in the Main array *****************************/

    index_l = 0;
    index_r = 0;
    for (index_a = left; index_l < size_left && index_r < size_right; index_a++)
    {
        if (L[index_l] < R[index_r])
        {
            A[index_a] = L[index_l];
            index_l++;
        }
        else
        {
            A[index_a] = R[index_r];
            index_r++;
        }
    }
    while (index_l < size_left)
    {
        A[index_a] = L[index_l];
        index_l++;
        index_a++;
    }
    while (index_r < size_right)
    {
        A[index_a] = R[index_r];
        index_r++;
        index_a++;
    }
}

void merge_sort(int A[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;

    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);

    merge(A, left, mid, right);
}

int main()
{
    int A[10];
    int i, n;
    cout << "Enter number of elements for the array : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Element - " << i + 1 << " = ";
        cin >> A[i];
    }
    merge_sort(A, 0, n - 1);

    cout << "After sorting : ";
    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}