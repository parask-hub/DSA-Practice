//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    void doUnion(int arr1[], int n, int arr2[], int m)
    {
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (arr1[i] < arr2[j])
                cout << arr1[i++] << " ";

            else if (arr2[j] < arr1[i])
                cout << arr2[j++] << " ";

            else
            {
                cout << arr2[j++] << " ";
                i++;
            }
        }

        /* Print remaining elements of the larger array */
        while (i < m)
            cout << arr1[i++] << " ";

        while (j < n)
            cout << arr2[j++] << " ";
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        ob.doUnion(a, n, b, m);
    }

    return 0;
}
// } Driver Code Ends