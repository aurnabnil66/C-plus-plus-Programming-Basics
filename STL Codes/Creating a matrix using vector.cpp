#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> data;

    int row,col,num;
    cout << "Enter row : ";
    cin >> row;
    cout << "Enter column : ";
    cin >> col;

    //vector<vector<int>> data(3, vector<int>(3, 5));   default way to create row columns without input

    cout << "Enter matrix elements : " <<endl;
    for (int i = 0; i < row; i++)
    {
        vector<int> v1;
        for (int j = 0; j < col; j++)
        {
            cin >> num;
            v1.push_back(num);
        }
        data.push_back(v1);
    }
    
    // showing the matrix
    cout << "The matrix is : " << endl;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    
}