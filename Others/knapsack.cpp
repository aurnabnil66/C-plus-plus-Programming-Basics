#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<pair<int, int>> weightProfit;
int n, bagCapacity, weight, profit;

void knapsack()
{
    // creating table
    for (int i = 0; i <= n; i++)
    {
        vector<int> row;
        for (int j = 0; j <= bagCapacity; j++)
        {
            // cout<<"enter a"<<i<<j<<endl;

            row.push_back(0);
        }
        v.push_back(row);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= bagCapacity; w++) // 23  34 45  56
        {
            if (weightProfit[i - 1].first <= w)
            {
                if ((weightProfit[i - 1].second + v[i - 1][w - weightProfit[i - 1].first]) > v[i - 1][w])
                {
                    v[i][w] = weightProfit[i - 1].second + v[i - 1][w - weightProfit[i - 1].first];
                }
                else
                {
                    v[i][w] = v[i - 1][w];
                }
            }
            else
            {
                v[i][w] = v[i - 1][w];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bagCapacity; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    // finding items
    int k = bagCapacity;
    int i = n;
    while (i != 0)
    {
        if (v[i][k] != v[i - 1][k])
        {
            cout << i << endl;
            i = i - 1;
            k = k - weightProfit[i].first;
        }
        else
        {
            i = i - 1;
        }
    }
}
int main()
{
    cout << "enter no of items" << endl;
    cin >> n;
    cout << "enter max bag capacity" << endl;
    cin >> bagCapacity;
    for (int i = 0; i < n; i++)
    {
        cout << "enter weight" << endl;
        cin >> weight;
        cout << "enter profit" << endl;
        cin >> profit;
        weightProfit.push_back(make_pair(weight, profit));
    }
    knapsack();
}
