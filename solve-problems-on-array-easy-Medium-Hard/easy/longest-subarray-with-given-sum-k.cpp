#include <iostream>
#include <vector>

using namespace std;

int lenOfMaxSubArraySumEqualK1(vector<int> &nums, int k)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            len++;
            if (sum == k)
            {
                maxLen = max(len, maxLen);
                len = 0;
                sum = 0;
                break;
            }
        }
    }

    return maxLen;

} // Tc: O(n*n), Sc: O(1)

int lenOfMaxSubArraySumEqualK2(vector<int> &nums, int k)
{
    
    int maxLen = 0;
    int sum = nums[0];
    int n = nums.size();

    int left = 0;
    int right = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum = sum - nums[left];
            left++;
        }

        if(sum == k){
            maxLen = max(maxLen , right - left + 1);
        }

        right++;

        if(right < n) sum = sum + nums[right];
    }
    return maxLen;

} // Tc: O(n), Sc: O(1)

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
        cout << lenOfMaxSubArraySumEqualK2(arr, k) << endl;
    }

    return 0;
}
