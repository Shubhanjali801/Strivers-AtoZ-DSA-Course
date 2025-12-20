#include <iostream>
using namespace std;

class Solution
{
public:
    void print1toN(int current,int num)
    {
        if (current > num)
            return;
        print1toN(current + 1, num);
            cout << current << " ";
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
         obj.print1toN(1,n); cout<<endl;
    }
    return 0;
}

