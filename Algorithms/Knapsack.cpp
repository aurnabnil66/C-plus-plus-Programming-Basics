#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<pair<int, int>> weight_profit;
int n, bag_capacity, weight, profit;

int knapsack()
{
    for (int i = 0; i <= n; i++)
    {
        vector<int> row;
        for (int j = 0; j <= bag_capacity; j++)
        {
            row.push_back(0);
        }
        v.push_back(row);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= bag_capacity; j++)
        {
            if (weight_profit[i - 1].first <= j)
            {
                if ((weight_profit[i - 1].second + v[i - 1][j - weight_profit[i - 1].first]) > v[i - 1][j])
                {
                    v[i][j] = weight_profit[i - 1].second + v[i - 1][j - weight_profit[i - 1].first];
                }
                else
                {
                    v[i][j] = v[i - 1][j];
                }
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    cout << "\nThe table will be : " << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bag_capacity; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return v[n][weight];
}

void find_items()
{
    int x = bag_capacity;
    int i = n;
    cout << "Optimal Knapsack should contain : ";
    while (i != 0)
    {
        if (v[i][x] != v[i - 1][x])
        {
            cout << i << " ";
            i = i - 1;
            x = weight_profit[i].first;
        }
        else
        {
            i = i - 1;
        }
    }
}

int main()
{
    cout << "Enter maximum capacity of the bag : ";
    cin >> bag_capacity;
    cout << "Enter number of items : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "weight : ";
        cin >> weight;
        cout << "profit : ";
        cin >> profit;
        cout << "\n";
        weight_profit.push_back(make_pair(weight, profit));
    }

    int value = knapsack();
    cout << "Maximum value that can be stored : " << value << endl;

    find_items();
}