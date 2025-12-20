#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findGcd1(int a, int b)
    {
        
        int gcd = 1;

        for (int i = 1; i <= min(a, b); ++i)
        {
            if (a % i == 0 && b % i == 0)
            {
                gcd = i;
            }
        }

        return gcd;
    } // O(min(a,b))

    int findGcd2(int a, int b)
    {

        for (int i = min(a, b); i > 0; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                return i;
            }
        }

        return 1;
    } // O(min(a,b))

    int findGcd3(int a, int b)
    {

        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }
        if (a == 0)
            return b;
        return a;
    } // O(min(a,b))
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
        int a, b;
        cin >> a >> b;

        // cout << obj.findGcd1(a,b) << endl;
        // cout << obj.findGcd2(a,b) << endl;
        cout << obj.findGcd3(a, b) << endl;
    }

    return 0;
}