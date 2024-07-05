#include<iostream>
using namespace std;
void swap(int *,int *);
int main()
{
    int n1,n2;
    cout << "Enter first number = ";
    cin >> n1;
    cout << "Enter second number = ";
    cin >> n2;
    cout << "Before Swapping : " <<endl;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "After Swapping : " << endl;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    swap(&n1,&n2);
    return 0;
}
void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}