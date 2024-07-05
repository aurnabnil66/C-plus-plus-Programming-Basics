#include <bits/stdc++.h>
using namespace std;
int n, r = 0, temp[100], temp1[100], c = 0;
double res[100], norm, mat[100][100], x;

int err()
{
    int flag = 1;

    for (int i = 0; i < n; i++)
    {

        temp1[i] = 1000 * res[i];
    }

    for (int i = 0; i < n; i++)
    {

        if (temp[i] == temp1[i])
        {

            flag = 1;
        }

        else
        {

            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {

        return 1;
    }

    else
    {

        return 0;
    }
}

int main()
{
    cout << "Enter number of variables : ";
    cin >> n;

    cout << "Enter the coefficient matrix : \n";
    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            cout << "b\n";
        }
        else
        {
            cout << "a" << i + 1 << "  ";
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> mat[i][j];
        }
        cout << "\n";
    }

    while (1)
    {

        c++;
        for (int i = 0; i < n; i++)
        {

            temp[i] = res[i] * 1000;
            res[i] = mat[i][n];

            for (int j = 0; j <= n; j++)
            {

                if (i != j)
                {

                    res[i] -= (mat[i][j] * res[j]);
                }
            }

            res[i] /= mat[i][i];
        }

        if (err())
        {

            break;
        }
    }

    printf("The roots are : \n");

    for (int i = 0; i < n; i++)
    {

        printf("X%d = %0.3lf\n", i + 1, res[i]);
    }

    cout << "\nTotal " << c << " iterations are needed" << endl;
    return 0;
}
