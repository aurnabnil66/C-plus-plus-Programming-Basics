#include<iostream>
using namespace std;
int search_element(int a[],int e,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == e)
        {
            return i;
        }
        
    }
    return -1;
    
}
int main()
{
    int arr[100];
    int n,x,i;
    cout << "Enter number of elements for the array : ";
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cout << "Element - " << i+1 << " = ";
        cin >> arr[i];
    }
    cout << "Enter the element you want to search : ";
    cin >> x;

    int result = search_element(arr,x,n);

    if (result == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << result;
    }
    
    
}

