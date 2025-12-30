#include <iostream>
#include <vector>

using namespace std;

int consecutiveOne(vector<int>&nums,int n){
    int maxOne = 0;
    int cnt1 = 0;

    for(int i=0; i < n ;i++){
        if(nums[i] == 1)cnt1++;
        else cnt1 = 0;
        maxOne = max(cnt1,maxOne);
    }
    return maxOne;

}// Tc: O(n), Sc: O(1)

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
        int n; cin>> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)cin >> arr[i];

        cout << consecutiveOne(arr,n) << endl;
    }

    return 0;
}
