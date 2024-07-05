#include<iostream>
using namespace std;
int main()
{
    int first,second;
    cout << "Enter the first interval = ";
    cin >> first;
    cout << "Enter the second interval = ";
    cin >> second;
    cout << "Prime numbers between " << first << " and " << second << " are : ";
    int i,j;
    for (i = first; i <= second; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
            
        }
        if (i == j)
        {
            cout << j << " ";
        }
        
    }
    
    return 0;
}