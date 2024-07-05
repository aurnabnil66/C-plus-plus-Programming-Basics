#include<bits/stdc++.h>
using namespace std;
bool func(int a, int b)
{
    return a < b;
}
int main()
{
    int ele,n;
    vector <int> vec1;

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        vec1.push_back(ele);
    }

    //sort(vec1.begin(), vec1.end(), func);  // for soring the whole vector
    
    sort(vec1.begin(), vec1.begin() + 4);  // for sorting first 4 elements

    cout << "After Sorting : ";
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }


}