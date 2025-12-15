#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:

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

   bool isPalindrome(long long num)
    {
        return num == reverseNumber2(num);
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
        
        cout<<obj.isPalindrome(n)<<endl;
       
    }

    return 0;
}