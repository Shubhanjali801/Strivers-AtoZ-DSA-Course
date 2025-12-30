#include <iostream>
#include <vector>

using namespace std;
void moveZeroesBruteForce(vector<int>&nums,int n){
    vector<int>temp(n,0);
    int k = 0;
    for(int i=0;i<n;i++){
        if(nums[i] != 0){
            temp[k++] = nums[i];
        }
    }
    nums = temp;      
}
void moveZeroesOptimal(vector<int>&nums,int n){
    int nonZeroIndex = 0;
    for(int i=0;i<n;i++){
        if(nums[i] != 0){
            swap(nums[i],nums[nonZeroIndex]);
            ++nonZeroIndex;
        }
    }    
}
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

        // moveZeroesBruteForce(arr,n);
        moveZeroesOptimal(arr,n);

        for (int i = 0; i < n; i++)cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
