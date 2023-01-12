// move all negative elements at beginning

#include <bits/stdc++.h>
using namespace std;

void reArrange(int arr[], int n)
{
    int i = 0, j = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
                }
        else
        {
            j++;
        }
    }
}
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Data
    int arr[] = {1, 2, -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    reArrange(arr, n);
    displayArray(arr, n);
    return 0;
}