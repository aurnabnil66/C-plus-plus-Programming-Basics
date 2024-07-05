#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
int main()
{
    vector<int> nums;
    int n, ele;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }

    cout << "New size : " << removeDuplicates(nums) << endl;
    
}
