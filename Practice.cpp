#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int testFunc(int i)
{
    if (i == 5)
    {
        return true;
    }
    return false;
}
int main()
{
    int x;
    for (int i = 1; i <= 5; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    
    int i = count(vec.begin(), vec.end(), 4);
    cout << i << endl;

    int j = count_if(vec.begin(), vec.end(), testFunc);
    cout << j << endl;

    

}