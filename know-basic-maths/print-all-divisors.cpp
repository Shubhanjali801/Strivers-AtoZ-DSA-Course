#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> printAlldivisor(int num){
        vector<int> divisors;

        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                divisors.push_back(i);
            }
        }

        return divisors;
    }
};
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int t; 
    cin >> t;
    while (t--)
    {
        Solution obj;
        int n;cin>>n;

        vector<int> ans = obj.printAlldivisor(n);
        for(int d : ans)cout<<d<<" "; cout<<endl;
    }

    return 0;
}