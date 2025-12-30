#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;
int removeDuplicates1(vector<int> &nums)
{
    unordered_set<int> seen;
    int index = 0;

    for (int num : nums)
    {
        if (seen.find(num) == seen.end())
        {
            seen.insert(num);
            nums[index] = num;
            index++;
        }
    }
    return index;
} // Tc: O(n), Sc: O(n);

int removeDuplicates2(vector<int> &nums)
{
    set<int> uniqueElements(nums.begin(), nums.end());
    int i = 0;
    for (int num : uniqueElements)nums[i++] = num;
    
    return uniqueElements.size();
} // Tc: O(n log n), Sc: O(n);


int removeDuplicates3(vector<int> &arr)
{
    if (arr.empty())return 0;
    auto last = unique(arr.begin(), arr.end());
    return distance(arr.begin(), last);

}  // Tc: O(n), Sc: O(1);


int removeDuplicates4(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
} // Tc: O(n), Sc: O(1)

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

        // int len = removeDuplicates1(arr);
        // int len = removeDuplicates2(arr);
        // int len = removeDuplicates3(arr);
        int len = removeDuplicates4(arr);

        for (int i = 0; i < len; i++)cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
