#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int i,n;
    int *ptr;
    cout << "Enter number of elements = ";
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cout << "Number - " << i+1 << " = ";
        cin >> arr[i]; 
    }
    ptr = arr;
    cout << "The elements are :" << endl;
    for ( i = 0; i < n; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;
    //cout << "Address of the first element = " << ptr << endl;
    //cout << "Value of the first element = " << *(arr) <<endl;
    //cout << "Address of the second element = " << (ptr +1) << endl;
    //cout << "Value of the second element = " << *(arr + 1) <<endl;
    //cout << "Address of the array = " << arr <<endl;

    int sum = 0;
    ptr = arr;
    for ( i = 0; i < n; i++)
    {
        sum = sum + *(ptr + i);
    }
    cout << "Sum of all the elements = " << sum << endl;
    
    ptr = arr;
    for ( i = 0; i < n; i++)
    {
        cout << *ptr << " " << "is situated in : "<< ptr;
        ptr++;
        cout << endl;
    }
    

    
}