#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    int ele,x,y;
    cout << "Enter array elements : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> ele;
        arr[i] = ele;
    }
    
    list <int> myList(arr, arr + 5);     // including the array in the list
    list <int>:: iterator it;

    cout << "Enter find item : ";
    cin >> x;
    cout << "Enter insert item : ";
    cin >> y;
    
    it = find(myList.begin(), myList.end(), x);       // finds the entered item  
    cout << *it << endl;     // printing where exactly the iterator is pointing to

    myList.insert(it, y);     // inserts the item before the find item

    cout << "List elements : ";
    for (it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }

    
}