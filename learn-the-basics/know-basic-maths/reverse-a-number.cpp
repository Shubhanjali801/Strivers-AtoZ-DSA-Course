#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long reverseNumber1(long long num)
    {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        return stoll(s);
    } // O(n);

    long long reverseNumber2(long long num)
    {
        long long rev = 0;
        while (num > 0)
        {
            int last = num % 10;
            rev = rev * 10 + last;
            num = num / 10;
        }
        return rev;
    } // O(log n);

    void reverseNumber3(long long num)
    {
        if (num < 10)
        {
            cout << num;
            return;
        }
        cout << num % 10;
        reverseNumber3(num / 10);
    } // O(log n);

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

        // cout<<obj.reverseNumber1(n)<<endl;
        cout<<obj.reverseNumber2(n)<<endl;

        // obj.reverseNumber3(n);
        // cout << endl;
    }

    return 0;
}