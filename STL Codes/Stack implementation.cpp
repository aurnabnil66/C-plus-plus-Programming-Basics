#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> numbers;
    int x;

    cout << "Pushing....." << endl;
    while (x >= 0)
    {
        cout << "Enter number : " << endl;
        cin >> x;
        if(x >= 0)
        {
            numbers.push(x);
        }
    }
    cout << "Elements in stack : "; 
    while (numbers.size() > 0)
    {
        cout << numbers.top();
        numbers.pop();
        cout << " ";
    }
    
    
}