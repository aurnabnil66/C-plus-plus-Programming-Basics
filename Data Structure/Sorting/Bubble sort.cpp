#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int n,x,i,j;
    cout << "Enter number of elements for the array : ";
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cout << "Element - " << i+1 << " = ";
        cin >> arr[i];
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                x = arr[j];
                arr[j] = arr[i];
                arr[i] = x;
            }
            
        }
        
    }
    cout << "Elements in the ascending order : ";
    for ( i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    
}