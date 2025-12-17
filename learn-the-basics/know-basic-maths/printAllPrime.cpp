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

    vector<int> printAllPrimesUpToN(int n)
    {
        vector<int>primes;

        for(int i = 2; i <= n; i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }

        return primes;
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
        int n; cin >> n;

        vector <int> res = obj.printAllPrimesUpToN(n);
        for(int prime: res)cout << prime << " "; cout << endl;
        
    }

    return 0;
}