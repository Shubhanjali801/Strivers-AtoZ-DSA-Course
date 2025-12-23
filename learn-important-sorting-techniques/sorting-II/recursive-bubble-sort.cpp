#include <iostream>
#include <vector>
using namespace std;

// Recursive function to perform Bubble Sort
void bubble_sortBrute(vector<int>&arr, int n) {
    // Base Case: If the array size is 1, it's already sorted
    if (n == 1) return;

    // Perform one pass of Bubble Sort: push the largest element to the end
    for (int j = 0; j <= n - 2; j++) {
        // Swap if elements are in the wrong order
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }

    // Recur for the remaining unsorted part (one less than before)
    bubble_sortBrute(arr, n - 1);
}

// Recursive Bubble Sort with early exit optimization
void bubble_sortOptimal(vector<int> &arr, int n) {
    // Base Case: if the size is 1, it's already sorted
    if (n == 1) return;

    int didSwap = 0; // Flag to check if any swap occurred in this pass

    // One pass: push the largest element to the end
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            // Swap arr[j] and arr[j + 1]
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1; // Mark that we did a swap
        }
    }

    // If no swap happened, array is already sorted
    if (didSwap == 0) return;

    // Recurse for the remaining unsorted portion
    bubble_sortOptimal(arr, n - 1);
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

        // Apply bubble_sort
        bubble_sortBrute(arr, n);
        // bubble_sortOptimal(arr, n);

        // Print sorted array
        for (int num : arr)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}