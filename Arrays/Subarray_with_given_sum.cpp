// Given an unsorted array A of size N that contains only non-negative integers
//  find a continuous sub-array which adds to a given number S.
// In case of multiple subarrays, return the subarray which comes first on moving from left to right

#include <bits/stdc++.h>
#include "My_Array.h" // using header file made by self
using namespace std;

void req_subarray(int a[], int n, int s)
{
    int start = 0;
    int end = -1;
    int cur_sum = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        cur_sum = cur_sum + a[i];
        if (cur_sum == s)
        {
            start = 0;
            end = i;
            break;
        }
        if (umap.find(cur_sum - s) != umap.end())
        {
            start = umap[cur_sum - s] + 1;
            end = i;
            break;
        }
        umap[cur_sum] = i;
    }
    if (end == -1)
    {
        cout << "Subarray Not Found " << endl;
        return;
    }
    cout << " The Subarray Between Index " << start << " to " << end << " Have Sum = " << s << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    Get_Array(a, n);
    int sum;
    cin >> sum;
    req_subarray(a, n, sum);
}