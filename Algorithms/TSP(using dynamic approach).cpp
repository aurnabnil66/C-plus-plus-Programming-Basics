#include <bits/stdc++.h>
using namespace std;
#define MAX 9999
int n = 4; // number of cities we want to visit
int graph[10][10] = {{0, 10, 15, 20},
                     {5, 0, 9, 10},
                     {6, 13, 0, 12},
                     {8, 8, 9, 0}};

// if all cities have been visited
int visited_all = (1 << n) - 1;   // 1 1 1 1

int Dp[16][4];

int tsp(int mask, int pos)
{
    if (mask == visited_all) // initially checking if all the cities are visited or not
    {
        return graph[pos][0]; // going back to origin from the current city
    }
    if (Dp[mask][pos] != -1)
    {
        return Dp[mask][pos];
    }

    int ans = MAX;
    // trying to go to unvisited nodes/cities
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)   // if current bit is 0 then that city is not visited
        {
            int newAns = graph[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return Dp[mask][pos] = ans;
}

int main()
{
    /* initialize the DP array */
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            Dp[i][j] = -1;
        }
    }
    int result = tsp(1, 0);
    cout << "Minimum Cost : " << result;
    return 0;
}