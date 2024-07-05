#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> unordered_map1;
    int n,val;
    string str;
    cout << "Enter number of items : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name : ";
        cin >> str;
        cout << "Enter marks : ";
        cin >> val;
        unordered_map1.insert({str,val});
    }

    cout << "Name -- Makrs" << endl;
    for(const auto & key_value : unordered_map1)
    {
        string name = key_value.first;
        int marks = key_value.second;

        cout << "-------------------------" << endl;
        cout << name << "     " << marks << endl;
    }
    
}