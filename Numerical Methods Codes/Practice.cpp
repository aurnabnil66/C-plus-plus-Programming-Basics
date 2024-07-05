#include <bits/stdc++.h>
using namespace std;
int n;
double mat[100][100], resNew[100], resOld[100];
double find_sum(int i)
{
    double sum = 0;
    for (int j = 0; j < n - 1; j++)
    {
        if (i != j)
        {
            sum = sum + fabs(mat[i][j]);
        }
    }
    return sum;
}
bool error()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fabs(mat[i][i]) > find_sum(i))
            {
                break;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
void jacobi_method()
{
    int flag = 0;
    for (int f = 1; f < n - 1; f++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            float sum = 0;
            for (int j = 0; j < n - 1; j++)
            {
                if (i != j)
                    sum = sum + mat[i][j] * resNew[j];
            }
            resNew[i] = (mat[i][n - 1] - sum) / mat[i][i];
        }

        for (int k = 0; k < n - 1; k++)
        {
            if (fabs(resOld[k] - resNew[k]) < 0.01)
                continue;
            else
                flag = 1;
        }
        if (flag == 0)
            break;

        flag = 0;
        for (int k = 0; k < n - 1; k++)
            resOld[k] = resNew[k];
    }
}
int main()
{
    cout << "Enter order of the matrix : ";
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Matrix " << i + 1 << " : " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    bool r = error();
    if (r == false)
    {
        cout << "Not Applicable";
    }
    else
    {
        jacobi_method();
        cout << "The roots are : " << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << resNew[i] << endl;
        }
        
    }
}