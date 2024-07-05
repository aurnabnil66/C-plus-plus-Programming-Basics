#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
int main()
{
    // Initializing vector of vectors
    vector<vector<int>> vec;

    // Elements to insert in the column
    int num = 10;

    // Inserting elements in the vector
    for (int i = 0; i < ROW; i++)
    {
        // vector to store column elements
        vector<int> v1;
        for (int j = 0; j < COL; j++)
        {
            v1.push_back(num);
            num += 5;
        }
        // Pushing back above 1D vector to create a 2D vector
        vec.push_back(v1);
    }
    // Displaying the 2D vector
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}