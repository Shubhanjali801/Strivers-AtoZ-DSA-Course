#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void frequencyOptimal(vector<int> nums, int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    int maxFreq = 0;
    int minFreq = n;

    int maxEle = 0;
    int minEle = 0;

    for (auto x : mp)
    {
        int element = x.first;
        int count = x.second;

        if (count > maxFreq)
        {
            maxFreq = count;
            maxEle = element;
        }

        if (count < minFreq)
        {
            minFreq = count;
            minEle = element;
        }
    }

    cout << maxEle << endl;
    cout << minEle << endl;

} // Tc: O(n), Sc: O(n)

void frequencyBruteforce(vector<int> nums, int n)
{

    vector<bool> visited(n, false);

    int maxFreq = 0;
    int minFreq = n;

    int maxEle = 0;
    int minEle = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
        {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                visited[j] = true;
                count++;
            }
        }

        if (count > maxFreq)
        {
            maxEle = nums[i];
            maxFreq = count;
        }

        // Update min frequency and corresponding element
        if (count < minFreq)
        {
            minEle = nums[i];
            minFreq = count;
        }
    }

    cout << maxEle << endl;
    cout << minEle << endl;

} // Tc: O(n*n), Sc: O(n)

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

        frequencyBruteforce(arr, n);cout << endl;
        frequencyOptimal(arr, n); cout << endl;
    }
    return 0;
}
