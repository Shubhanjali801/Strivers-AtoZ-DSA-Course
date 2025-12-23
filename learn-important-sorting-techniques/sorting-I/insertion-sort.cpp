#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size(); 
        
        for (int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1; 
            
            // Shift elements that are greater than key by one position
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            
            nums[j + 1] = key; // Insert key at correct position
        }
        
        return nums;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    
        Solution solution;
        arr = solution.insertionSort(arr);

        // Print sorted array
        for (int num : arr)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}