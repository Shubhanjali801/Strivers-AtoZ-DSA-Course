#include <iostream>
#include <vector>
using namespace std;
bool isSortedAndRotated(vector<int>& arr) {
    
    int count = 0;

    for(int i=0;i<arr.size();i++){
        // check how many time curr element greater than next element 
        if(arr[i] > arr[(i + 1) % arr.size()])count++;
    }
    
    // if it is more than one return false, o.w. return true;
    if(count > 1)return false;
    else return true;  
    
}  // Tc: O(n), Sc: O(1)


bool isSorted1(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
} // Tc: O(n), Sc: O(1)

bool isSorted2(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                return false;
        }
    }
    return true;
} // Tc: O(n^2), Sc: O(1)

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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // cout << isSorted1(arr, n) << endl;
        // cout << isSorted2(arr, n) << endl;
        cout << isSortedAndRotated(arr) <<endl;
    }

    return 0;
}