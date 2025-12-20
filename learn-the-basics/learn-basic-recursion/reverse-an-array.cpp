#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Helper recursive function
void reverseArrayRec(vector<int> &arr, int i) {
    int n = arr.size();
    
    // Base Case
    if (i >= n - i - 1)
        return;
        
    // Swap
    swap(arr[i], arr[n - i - 1]);
    
    // Recursive call
    reverseArrayRec(arr, i + 1);
}

void reverseArray(vector<int> &arr) {
    reverseArrayRec(arr, 0);
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
        vector<int> arr(n); for(int i=0;i<n;i++)cin>>arr[i];
        
        Solution obj;
        obj.reverseArray(arr);

         for(int i=0;i<n;i++)cout<<arr[i]<<" "; cout<<endl;
    }
    return 0;
}
