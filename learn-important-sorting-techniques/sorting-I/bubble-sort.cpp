#include <iostream>
#include <vector>
using namespace std;

class BubbleSort {
public:
    void bubble_sortOptimal(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            int didSwap = 0; //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]); 
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }
    }
    void bubble_sortBrute(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {  //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }    
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
    
        BubbleSort sorter;
        sorter.bubble_sortBrute(arr);
        // sorter.bubble_sortOptimal(arr);

        // Print sorted array
        for (int num : arr)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}