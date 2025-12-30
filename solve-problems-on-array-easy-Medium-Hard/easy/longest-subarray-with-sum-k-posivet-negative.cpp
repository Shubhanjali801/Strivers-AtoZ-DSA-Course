#include <iostream>
#include <vector>
#include <map>

using namespace std;

int lenOfMaxSubArraySumEqualK1(vector<int> &nums, int k)
{
    int len = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;

} // Tc: O(n*n*n), Sc: O(1)

int lenOfMaxSubArraySumEqualK2(vector<int> &nums, int k)
{
    int len = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)len = max(len, j - i + 1);   
        }
    }

    return len;

} // Tc: O(n*n), Sc: O(1)


int lenOfMaxSubArraySumEqualK3(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> preSumMap; // prefixSum -> earliest index
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i]; // compute running prefix sum
      
        if (sum == k)maxLen = max(maxLen, i + 1);

        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) preSumMap[sum] = i;
        
    }

    return maxLen;

}// Tc: O(n log n), Sc: O(1)


int main()
{

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // cout << lenOfMaxSubArraySumEqualK1(arr, k) << endl;
        // cout << lenOfMaxSubArraySumEqualK2(arr, k) << endl;
        cout << lenOfMaxSubArraySumEqualK3(arr, k) << endl;
    }

    return 0;
}
