#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> unionOfSortedArraysOptimal(const vector<int>& arr1, const vector<int>& arr2) {
 vector<int> result;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        } else { // arr1[i] == arr2[j]
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < arr1.size()) {
        if (result.empty() || result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements from arr2
    while (j < arr2.size()) {
        if (result.empty() || result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result;

}// Tc:((n1+n1)), Sc: O(n1+n2)

vector<int> UnionFirstApp1(vector<int>&num1, vector<int>&num2){
    int n1 = num1.size();
    int n2 = num2.size();

    map<int,int>freq;
    vector<int>Union;

    for(int i=0;i<n1;i++) freq[num1[i]++];
    
    for(int i=0;i<n2;i++) freq[num2[i]++];
    
    for(auto x : freq) Union.push_back(x.first);

    return Union;

}// Tc:((n1+n1)log(n1+n2)), Sc: O(n1+n2)


vector<int> UnionFirstApp2(vector<int>&num1, vector<int>&num2){
    int n1 = num1.size();
    int n2 = num2.size();

    set<int>s;

    for(int i=0;i<n1;i++) s.insert(num1[i]);
    
    for(int i=0;i<n2;i++) s.insert(num2[i]);
    
    vector<int>Union(s.begin(),s.end());

    return Union;

}// Tc:((n1+n1)log(n1+n2)), Sc: O(n1+n2)


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

        int n1,n2; cin>> n1>> n2;

        vector<int> arr1(n1);
        vector<int> arr2(n2);

        for (int i = 0; i < n1; i++)cin >> arr1[i];
        for (int i = 0; i < n2; i++)cin >> arr2[i];

        // vector<int> ans = UnionFirstApp1(arr1,arr2);
        // vector<int> ans = UnionFirstApp2(arr1,arr2);
        vector<int> ans = unionOfSortedArraysOptimal(arr1,arr2);
        
        for(auto x : ans )cout<< x << " ";cout<<endl;

    }

    return 0;
}