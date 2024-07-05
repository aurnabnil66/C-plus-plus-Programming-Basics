#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

void quick_sort(int A[], int f, int l)
{
    if(f < l)
    {
        int x;
        int i = f + 1, j = l;
        while(i < j)
        {
            while(A[i] <= A[f])
            {
                i++;
            }
            while(A[j] >= A[f])
            {
                j--;
            }
            if(i < j)
            {
                x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
        x = A[j];
        A[j] = A[f];
        A[f] = x;

        quick_sort(A, f, j - 1);
        quick_sort(A, j + 1, l);
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
