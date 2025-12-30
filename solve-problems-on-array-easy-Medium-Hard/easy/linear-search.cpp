#include <iostream>
#include <vector>

using namespace std;
int LinearSearch(vector<int>&nums,int target){
   int n = nums.size();
   for(int i=0;i<n;i++){
    if(nums[i] == target)return i;
   }
   return -1;
}


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
        int key ; cin>>key;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << LinearSearch(arr,key) << endl;

    }

    return 0;
}