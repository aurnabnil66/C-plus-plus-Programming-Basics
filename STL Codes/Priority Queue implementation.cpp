#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> numbers;
    int x;
    cout << "Inserting Elements : " << endl;
     while (x >= 0)
    {
        cout << "Enter number : " << endl;
        cin >> x;
        if(x >= 0)
        {
            numbers.push(x);
        }
    }
    cout << "Elements in priority queue : "; 
    while (numbers.size() > 0)
    {
        cout << numbers.top();
        numbers.pop();
        cout << " ";
    }
    
}