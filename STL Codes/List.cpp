#include<bits/stdc++.h>
using namespace std;
int main()
{
    list <int> myList;
    list <int>::iterator it;
    
    myList.push_front(5);       // adding in first
    myList.push_front(10);
    myList.push_front(15);
    myList.push_back(-1);
    myList.push_back(-2);     // adding in last
    
    cout << "List elements : ";
    for (it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }

    myList.reverse();   // prints the list in reverse
    
    cout << "\nList elements in reverse : ";
    for (it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }

    int s = myList.size();
    cout << "Size : " << s << endl;
}