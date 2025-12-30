#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int largestEle1(vector<int> &arr, int n)
{
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
} // Tc: O(n), Sc: O(1)


int smallestEle1(vector<int> &arr, int n)
{
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
} // Tc: O(n), Sc: O(1)


int largestEle2(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    return arr[n - 1];
} // Tc: O(nlog n), Sc: O(1)


int smallestEle2(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());

    return arr[0];
} // Tc: O(nlog n), Sc: O(1)


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

        // largest element
        // cout << largestEle1(arr, n) << endl;
        // cout << largestEle2(arr, n) << endl;


        // smallest element
        // cout << smallestEle1(arr, n) << endl;
        cout << smallestEle2(arr, n) << endl;
    }

    return 0;
}
