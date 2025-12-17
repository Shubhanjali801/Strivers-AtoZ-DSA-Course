#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        if(n <= 1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0)return false;
        }
        return true;
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

        cout<< obj.isPrime(n);
        cout<<endl;
        
    }

    return 0;
}