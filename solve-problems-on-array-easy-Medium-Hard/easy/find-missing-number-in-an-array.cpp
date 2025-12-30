#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int missingNumber0(vector<int>&nums,int n){
    n = n + 1;
    for(int i = 1; i <= n ; ++i){
        bool found = false;
        for(int j = 0; j < n - 1 ;j++){
            if(nums[j] == i){
                found = true;
                break;
            }
        } 
        if(!found)return i; // missing element
    }
    return -1;

}// Tc:(n*n), Sc: O(1)


int missingNumber1(vector<int>&nums,int n){
    sort(nums.begin(),nums.end());

    for(int i=1; i<=n ; ++i){
        if(nums[i-1] != i)return i;  // missing element 
    }
    return -1;

}// Tc:(n log n), Sc: O(1)

int missingNumber2(vector<int>&nums,int n){
    n = n + 1;
    vector<int> hash(n + 1,0);
    // for(auto x : hash) cout << x << " ";

    for(int i = 0; i < n - 1 ;i++){
        hash[nums[i]]++;
    }
    // for(auto x : hash) cout << x << " ";

    for(int i = 1; i <= n;i++){
        if(hash[i] == 0)
        return i; // missing element
    }
    return -1;

}// Tc:(n ), Sc: O(n)

int missingNumber3(vector<int>&nums,int n){
    n = n + 1;
    long long sumOfNaturalNumber = (n * 1LL * (n + 1))/2;
    int sumOfNums = accumulate(nums.begin(),nums.end(),0);
    
    return sumOfNaturalNumber - sumOfNums; // missing number

}// Tc:(n), Sc: O(1)

int missingNumber4(vector<int>&nums,int n){
    n = n + 1;
    
    int xor1 = 0;
    int xor2 = 0;

    // xor of all array element
    for(int i = 0;i < n-1; i++){
        xor2 ^= nums[i];
    }

    // xor of element from 1 to n
    for(int i=1; i <= n;i++){
        xor1 ^= i;
    }

    return xor2 ^ xor1;// missing number

}// Tc:(n), Sc: O(1)


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

        // cout << missingNumber0(arr,n);
        // cout << missingNumber1(arr,n);
        // cout << missingNumber2(arr,n);
        // cout << missingNumber3(arr,n);
        cout << missingNumber4(arr,n);

    }

    return 0;
}