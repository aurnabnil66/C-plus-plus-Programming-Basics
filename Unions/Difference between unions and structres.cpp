#include<iostream>
using namespace std;
union Person1
{
    char name[30];
    double age;
    int income;
    float weight;
};
struct Person2
{
    char name[30];
    double age;
    int income;
    float weight;
};
int main()
{
    union Person1 x;
    struct Person2 y;
    cout << "Size of Union = " << sizeof(x) << endl;
    cout << "Size of Struct = " << sizeof(y) << endl;
}

