#include <iostream>

using namespace std;
#define nl '\n';

class Solution
{
public:
    void printName(string name, int count, int N)
    {
        if (count == N)
            return;

        cout << name << nl;
        printName(name, count + 1, N);
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

        string name;
        cin >> name;
        int N;
        cin >> N;

        obj.printName(name, 0, N);
        cout << nl;
    }

    return 0;
}