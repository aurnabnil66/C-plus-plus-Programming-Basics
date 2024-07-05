#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    int memory[n];
    if(n < 0)
    {
        cout << "Error";
    }
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int sum = fib(n - 1) + fib(n - 2);
    if (memory[n] != NULL)
    {
        memory[n] = sum;
    }
    
    return sum;
    
}
int main()
{
    int n;
    cout << "Enter number of terms : ";
    cin >> n;

    int result = fib(n);
    cout << result;

}