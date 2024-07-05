#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ele,n;
    vector <int> vec1;
    vector <int> :: iterator it;

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        vec1.push_back(ele);
    }

    cout << "Actual vector : ";
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
    
    cout << "From Iterator : ";
    for ( it = vec1.begin(); it != vec1.end(); it++)
    {
        cout << *it << " ";       // iterator is basically a pointer which is used to access vector elements
    }
    
    return 0;
    
}