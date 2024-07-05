#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    int n,j,x;
    int a[n],p[n];
    cout << "Enter highest power : ";
    cin >> n;
    cout << "Enter a3 : ";
    cin >> a[3];
    cout << "Enter a2 : ";
    cin >> a[2];
    cout << "Enter a1 : ";
    cin >> a[1];
    cout << "Enter a0 : ";
    cin >> a[0];
    cout << "Enter x : ";
    cin >> x;

    j = n;
    p[n] = a[n];
    while(j >= 0)
    {
        p[j - 1] = a[j - 1] + p[j] * x;
        j--;
    }

    cout << "Answer is " << p[0];

}
