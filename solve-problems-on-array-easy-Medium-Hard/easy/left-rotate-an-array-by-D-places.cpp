#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reverse(vector<int> &nums,int start,int end){
    while(start < end){
        swap(nums[start],nums[end]);
        ++start;
        --end;
    }
}
void rotateLeftOptimal(vector<int>& nums, int k) {
   int n = nums.size();
   k = k % n;

   // step 1 : reverse first k elements
   reverse(nums, 0, k-1);

   // step 2 : reverse remaining n - k elements 
   reverse(nums, k, n - 1);

   // step 3 : reverse entire array 
   reverse(nums, 0, n - 1);

}// Tc: O(n), Sc: O(1)

void rotateRightOptimal(vector<int>& nums, int k) {
   int n = nums.size();
   k = k % n;
   k = n - k; // convert right rotation to left rotation

   // step 1 : reverse first k elements
   reverse(nums, 0, k-1);

   // step 2 : reverse remaining n - k elements 
   reverse(nums, k, n - 1);

   // step 3 : reverse entire array 
   reverse(nums, 0, n - 1);

}// Tc: O(n), Sc: O(1)

void rotateLeftBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) return;
    
    // Create a temporary array to store the first k elements
    vector<int> temp(nums.begin(), nums.begin() + k);
    
    // Shift the remaining n - k elements to the left by k positions
    for (int i = 0; i < n - k; ++i) {
        nums[i] = nums[i + k];
    }
    
    // Copy the elements from the temporary array to the end of the array
    for (int i = 0; i < k; ++i) {
        nums[n - k + i] = temp[i];
    }

}// Tc: O(n), Sc: O(k)


void rotateRightBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) return;
    
    // Create a temporary array to store the last k elements
    vector<int> temp(nums.end() - k, nums.end());
    for(auto x : temp) 
    // Shift the first n - k elements to the right by k positions
    for (int i = n - 1; i >= k; --i) {
        nums[i] = nums[i - k];
    }
    
    // Copy the elements from the temporary array to the beginning of the array
    for (int i = 0; i < k; ++i) {
        nums[i] = temp[i];
    }
} // Tc: O(n), Sc: O(k)

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
        int k;
        cin >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // rotateRightBruteForce(arr,k);
        // rotateLeftBruteForce(arr,k);
        // rotateRightOptimal(arr,k);
        rotateLeftOptimal(arr,k);

        for (int i = 0; i < n; i++)cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}