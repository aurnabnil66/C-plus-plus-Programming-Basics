#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p = 1, v = 1;
    double res[100], pivot, mat[100][100];
    
    cout << "Enter the number of variables : ";
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

    // Forward Elimination
    while (v < n)
    {
        for (int i = v; i < n; i++)
        {

            pivot = -(mat[i][i - p] / mat[i - p][i - p]);

            for (int j = 0; j <= n; j++)
            {

                mat[i][j] = mat[i][j] + (pivot * mat[i - p][j]);
            }

            p++;
        }

        p = 1;
        v++;
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= n; j++)
        {

            printf("%lf\t", mat[i][j]);
        }

        cout << "\n";
    }

    // Backward Substitution
    for (int i = n - 1; i > -1; i--)
    {

        res[i] = 0;
    }

    for (int i = n - 1; i > -1; i--)
    {

        res[i] = mat[i][n];

        for (int j = n - 1; j > 0; j--)
        {

            if (i == n - 1)
            {

                break;
            }

            else
            {

                if (j > i)
                {

                    res[i] -= (mat[i][j] * res[j]);
                }

                else
                {

                    break;
                }
            }
        }

        res[i] /= mat[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("X%d = %lf\n", i + 1, res[i]);
    }
}