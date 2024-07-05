#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, r = 0;
    double x, res[100], norm, mat[100][100];

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

    while (r < n)
    {

        norm = 1 / mat[r][r];

        // normalize
        for (int i = 0; i <= n; i++)
        {

            mat[r][i] = mat[r][i] * norm;
        }

        // removing x
        for (int i = 0; i < n; i++)
        {

            x = mat[i][r];

            for (int j = 0; j <= n; j++)
            {

                if (i != r)
                {

                    mat[i][j] -= (x * mat[r][j]);
                }

                else
                {

                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j <= n; j++)
            {

                printf("%lf\t", mat[i][j]);
            }

            printf("\n");
        }

        printf("\n");
        r++;
    }

    // roots
    for (int i = 0; i < n; i++)
    {

        res[i] = mat[i][n] / mat[i][i];
    }

    printf("The roots are : \n");

    for (int i = 0; i < n; i++)
    {

        printf("X%d = %lf\n", i + 1, res[i]);
    }

    return 0;
}
