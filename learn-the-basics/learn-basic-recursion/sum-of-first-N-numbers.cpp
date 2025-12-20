#include <iostream>
using namespace std;

class Solution
{
public:
    int SumOfFirstNaturalNumber(int num)
    {
        if (num == 1)
            return 1;
        return num + SumOfFirstNaturalNumber(num - 1);
    }
};

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
        int n;cin>>n;
        
        Solution obj;
        cout << obj.SumOfFirstNaturalNumber(n) << endl;
    }
    return 0;
}


