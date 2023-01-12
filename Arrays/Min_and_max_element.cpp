// Maximum and minimum of an array using minimum number of comparisons
// Given an array of size N.The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    cout << "MAX : " << maxi << endl
         << "MIN : " << mini << endl;
}