#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long countDigits1(long long num)
    {
        string s = to_string(num);
        long long len = s.size();
        return len;
    }

    long long countDigits2(long long num)
    {
        long long cnt = 0;
        while (num > 0)
        {
            long long rem = num % 10;
            ++cnt;
            num = num / 10;
        }
        return cnt;
    }

    long long countDigits3(long long num)
    {
        long long cnt = (int)log10(num) + 1;
        return cnt;
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
        long long n;
        cin >> n;
        cout<<obj.countDigits1(n)<<endl;
        // cout<<obj.countDigits2(n)<<endl;
        // cout << obj.countDigits3(n) << endl;
    }

    return 0;
}