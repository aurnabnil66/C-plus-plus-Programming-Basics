#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a positive integer = ";
    cin >> n;
    int i;
    for (i = 1; i <= 10; i++)
    {
        cout << n << "X" << i << "=" << n*i << endl;
    }
    

}