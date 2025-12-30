#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int secondSmallestEle1(vector<int> &arr, int n)
{
    if( n < 2) return -1;

    int smallest = INT_MAX;
    int secondsmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondsmallest = smallest;
            smallest = arr[i];
        }
        if (arr[i] < secondsmallest && arr[i] > smallest) secondsmallest = arr[i];
        
    }
    return secondsmallest;

}//  Tc : O(n), Sc: O(1)


int secondLargestEle1(vector<int> &arr, int n)
{
    if( n < 2) return -1;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        if (arr[i] > secondLargest && arr[i] < largest)secondLargest = arr[i];
        
    }
    return secondLargest;

}//  Tc : O(n), Sc: O(1)


int secondLargestEle2(vector<int> &arr, int n)
{
    sort(arr.begin(),arr.end());
    return arr[n-2] ;

} // Tc : O(n log n), Sc: O(1)

int secondSmallestEle2(vector<int> &arr, int n)
{
    sort(arr.begin(),arr.end());
    return arr[0] ;
    
} // Tc : O(n log n), Sc: O(1)

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
        // cout << secondLargestEle1(arr, n) <<endl;
        cout << secondLargestEle2(arr, n) <<endl;

        // smallest element
        // cout << secondSmallestEle1(arr, n) <<endl;
        // cout << secondSmallestEle2(arr, n) <<endl; 
    }

    return 0;
}