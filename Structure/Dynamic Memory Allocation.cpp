#include<iostream>
using namespace std;
struct Person
{
    int age;
    double weight;
    char name[20];
};
int main()
{
    struct Person *PersonPtr;
    int i,n;
    cout << "Enter number of persons : ";
    cin >> n;
    PersonPtr = (struct Person*) malloc (n*sizeof(struct Person));
    for ( i = 0; i < n; i++)
    {
        cout << "Name : " ;
        cin >> (PersonPtr + i) -> name;
        cout << "Age : " ;
        cin >> (PersonPtr + i) -> age;
        cout << "Weight : " ;
        cin >> (PersonPtr + i) -> weight;
 
    }
    cout << "\nDisplaying Information\n";
    for ( i = 0; i < n; i++)
    {
        cout << "Name : " << (PersonPtr + i) -> name << endl;
        cout << "Age : " << (PersonPtr + i) -> age << endl;
        cout << "Weight : " << (PersonPtr + i) -> weight << endl;
    }
    
    
}
