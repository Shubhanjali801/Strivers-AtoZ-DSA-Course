#include <iostream>
#include <vector>
using namespace std;


// Recursive insertion sort function
void insertion_sort(vector<int> &arr, int i, int n) {
    // Base Case: if index reaches the size, return
    if (i == n) return;

    int j = i;
    // Shift the element to the left while it's smaller than its predecessor
    while (j > 0 && arr[j - 1] > arr[j]) {
        // Swap arr[j] and arr[j-1]
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    // Recur for the next index
    insertion_sort(arr, i + 1, n);
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
    

        // Apply insertion_sort
        insertion_sort(arr, 0, n);

        // Print sorted array
        for (int num : arr)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
