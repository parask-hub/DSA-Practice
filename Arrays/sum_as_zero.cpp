
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
        bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> sumHash;

        int currSum = 0;
        for (int i = 0; i < n; i++)
        {

            currSum += arr[i];
            if (currSum == 0 || sumHash.find(currSum) != sumHash.end())
                return true;
            sumHash.insert(currSum);
        }
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
