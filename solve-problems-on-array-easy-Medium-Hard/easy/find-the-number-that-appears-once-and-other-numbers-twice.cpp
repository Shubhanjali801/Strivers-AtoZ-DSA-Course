#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int singleNumber1(vector<int>&nums,int n){
    
    for(int i=0; i<n;i++){
        int num = nums[i];
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(nums[j] == num) cnt++;
        }
        if(cnt == 1) return num;
    }
    return -1;

}// Tc: O(n*n), Sc: O(1)

int singleNumber2(vector<int>&nums,int n){
    
    int maxi = *max_element(nums.begin(),nums.end());

    vector<int> hash(maxi + 1, 0);

    // count freq of each element
    for(auto x : nums)hash[x]++;

    // Find the element with frequency == 1
    for(int i = 0; i<n ; i++){
        if(hash[nums[i]] == 1)return nums[i];
    }
    return -1;

}// Tc: O(n+n+n), Sc: O(maxi + 1)

int singleNumber3(vector<int>&nums,int n){
    
    unordered_map<int,int>mp;

    // Find freq of each element
    for(auto x : nums)mp[x]++;

    // Find the element with frequency == 1
    for(auto y: mp){
        if(y.second == 1)return y.first;
    }
    return -1;

}// Tc: O(n+n), Sc: O(n)

int singleNumber4(vector<int>&nums,int n){
    
    int xorr = 0;
    for(int i=0; i < n; i++){
        xorr ^= nums[i];
    }

    return xorr;

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

        // cout << singleNumber1(arr,n) << endl;
        // cout << singleNumber2(arr,n) << endl;
        // cout << singleNumber3(arr,n) << endl;
        cout << singleNumber4(arr,n) << endl;
    }

    return 0;
}

