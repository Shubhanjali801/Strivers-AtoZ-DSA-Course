#include <iostream>
#include <vector>
using namespace std;

void rotateArrayByOne(vector<int> &nums)
{
    int n = nums.size();

    nums[n - 1] = nums[0];
    for (int i = 1; i < n - 1; i++)
        nums[i - 1] = nums[i];

} // Tc: O(n), Sc: O(1)

void rotate1(vector<int> &nums, int k)
{
   int n = nums.size();
   k = k % n;

   for(int i=0;i<k;++i){
    int last = nums.back();
    nums.pop_back();
    nums.insert(nums.begin(),last);
   }

}// Tc: O(k*n), Sc: O(1)

void reverse(vector<int>&nums,int start,int end){
    while(start < end){
        swap(nums[start],nums[end]);
        ++start;
        --end;
    }
}
void rotate2(vector<int> &nums, int k)
{
   int n = nums.size();
   k = k % n;

   reverse(nums, 0, n - 1);
   reverse(nums, 0, k - 1);
   reverse(nums, k, n - 1);

}// Tc: O(n), Sc: O(1)

void rotate3(vector<int> &nums, int k)
{
   int n = nums.size();
   k = k % n;

   vector<int> temp(n);
   for(int i=0; i<n;++i){
    temp[(i + k) % n] = nums[i];
   }

   nums = temp;

}// Tc: O(n), Sc: O(n)

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

        // rotateArrayByOne(arr);
        // rotate1(arr, k);
        // rotate2(arr, k);
        rotate3(arr, k);

        for (int i = 0; i < n; i++)cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
