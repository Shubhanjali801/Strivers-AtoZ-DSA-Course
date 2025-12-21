#include <iostream>
#include <vector>
using namespace std;

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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int query; cin >> query;   
        
        // precompute
        int hash[13] = {0};
        for(int i=0;i<n;i++){
            hash[arr[i]] += 1;
        }

        // fetch 
        while(query--){
            int number ; cin >> number;

             cout<<hash[number]<<endl;
        }
    }
    return 0;
} // TC: O(n)

