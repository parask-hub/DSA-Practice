#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swap in row
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            int l = n - 1;
            while (k < l)
            {
                swap(matrix[i][k], matrix[i][l]);
                k++;
                l--;
            }
        }
    }
};