#include <iostream>
#include <vector>
using namespace std;

// Works for ascending array
int binarySearch(vector<int> &nums, int target)
{
    // st => starting element index
    // end => ending element index
    // mid => middle element index
    int st = 0, end = nums.size() - 1, mid;
    while (st <= end)
    {
        // mid = (st + end) / 2;
        /* In the worst case scenario, both st and end
        become INT_MAX, so adding them leads to overflow.
        To avoid that, the alternative formula for mid is: */
        mid = st + (end - st) / 2;
        if (target > nums[mid])
            st = mid + 1; // 2nd half
        else if (target < nums[mid])
            end = mid - 1; // 1st half
        else
            return mid;
    }
    return -1;
}

int recursiveBS(vector<int> &arr, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (tar > arr[mid])
            return recursiveBS(arr, tar, mid + 1, end);
        else if (tar < arr[mid])
            return recursiveBS(arr, tar, st, mid - 1);
        else
            return mid;
    }
    return -1;
}

int main()
{
    /* Binary Search Algorithm */

    // General Points:
    // This is like searching for a word in a dictionary.
    // This is a better algorithm than linear search.
    // This works only for sorted arrays.
    // Sorted arrays can be ascending or descending.
    // Examples of sorted arrays: 1) [2,9,14,25,36] 2) [10,5,2,1]
    // Time Complexity = O(log n).
    // Time Complexity = O(1).

    // Code:
    int n, target;
    // input size
    cout << "Enter the size of sorted array = ";
    cin >> n;
    // input arr
    vector<int> arr(n);
    cout << "\nEnter the elements of the sorted array :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> arr[i];
    }
    // input target
    cout << "Enter the required number = ";
    cin >> target;
    // output
    cout << "Target is found at " << binarySearch(arr, target) << " index." << endl;

    // Binary Search with recursion //

    // Previous code is more optimized than this code.
    // Time Complexity = O(log n).
    // Space Complexity = O(log n).
    cout << "\nBinary Search with recursion\n"
         << endl;
    int result = recursiveBS(arr, target, 0, n);
    if (result != -1)
        cout << "Target is found at " << result << " index.";
    else
        cout << "Target not found." << endl;

    return 0;
}