#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool isArmstrong(int num)
    {
        int noOfdigit = to_string(num).size();

        int n = num;
        int sum = 0;

        while (n > 0)
        {
            int last = n % 10;
            sum += pow(last, noOfdigit);
            n = n / 10;
        }

        if (sum == num)
            return 1;
        else
            return 0;
    } // O(log n)
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

        cout << obj.isArmstrong(n) << endl;
    }

    return 0;
}