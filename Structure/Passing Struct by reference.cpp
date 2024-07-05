#include<iostream>
using namespace std;
typedef struct Number
{
    double real;
    double imag;
} complex;
void addNumbers(complex x , complex y, complex *result);
int main()
{ 
    complex n1,n2,result;
    cout << "For 1st Number :\n";
    cout << "Enter real part = ";
    cin >> n1.real;
    cout << "Enter imaginary part = ";
    cin >> n1.imag;

    cout << "For 2nd Number :\n";
    cout << "Enter real part = ";
    cin >> n2.real;
    cout << "Enter imaginary part = ";
    cin >> n2.imag;

    addNumbers(n1,n2,&result);
    cout << "\nReal = " << result.real << endl;
    cout << "\nImaginary = " << result.imag << endl;  
}
void addNumbers(complex x , complex y, complex *result)
{
    result -> real = x.real + y.real;
    result -> imag = x.imag + y.imag;
}