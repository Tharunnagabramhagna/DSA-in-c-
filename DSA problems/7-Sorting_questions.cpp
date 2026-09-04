#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArrBef(vector<int> &arr)
{
    cout << "Array Before Sorting:\n";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void printArrAft(vector<int> &arr)
{
    cout << "Array After Sorting:\n";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void sortVec(vector<int> &arr)
{
    // Time Complexity: O(n log n)
    // Space Complexity: O(1)
    sort(arr.begin(), arr.end());
    // We can also use Selection Sort or Insertion Sort.
    /* However, this approach is better in terms of
       time complexity. (Selection/Insertion Sort => O(n^2)) */
}

void sortVecOp(vector<int> &nums)
{
    // Time Complexity: O(n + n) = O(2n) = O(n)
    // Space Complexity: O(1) => 2 passes
    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;

    // First pass: count occurrences of 0, 1, and 2
    for (int val : nums)
    {
        if (val == 0)
            count0++;
        else if (val == 1)
            count1++;
        else
            count2++;
    }

    int idx = 0;
    // Second pass: overwrite array based on counts
    for (int i = 0; i < count0; i++)
        nums[idx++] = 0;
    for (int i = 0; i < count1; i++)
        nums[idx++] = 1;
    for (int i = 0; i < count2; i++)
        nums[idx++] = 2;
}

void sortColors(vector<int> &nums)
{
    // Dutch National Flag Algorithm
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        { // Case for 2
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}

void mergeArr(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;
    while (j >= 0)
    {
        if (i >= 0 && arr1[i] > arr2[j])
            // to arrange elements in arr1
            arr1[idx--] = arr1[i--];
        // idx--; i--;
        else
            // to replace elements of arr1 with arr2
            arr1[idx--] = arr2[j--];
        // idx--; j--;
    }
}

int main()
{
    // /* Sort Colors */
    // // LeetCode Problem 75

    // // 1) Brute Force Approach
    // cout << "__ Brute Force Approach __\n";
    // vector<int> vec = {2, 0, 2, 1, 1, 0};
    // printArr0(vec);
    // sortVec(vec);
    // printArr1(vec);

    // // 2) Counting Approach
    // cout << "\n__ Optimal Approach __\n";
    // vector<int> Vec = {2, 0, 1, 0, 2};
    // printArr0(Vec);
    // sortVecOp(Vec);
    // printArr1(Vec);

    // // 3) Dutch National Flag Algorithm
    // cout << "\n__ Optimized Approach __\n";
    // int N;
    // // Input size
    // cout << "Enter the size of the array: ";
    // cin >> N;

    // // Input arr
    // vector<int> arr(N);
    // for (int i = 0; i < N; i++)
    // {
    //     cout << "Enter element (0, 1, or 2) at index " << i << ": ";
    //     cin >> arr[i];
    // }

    // // Output
    // printArr0(arr);
    // sortColors(arr);
    // printArr1(arr);

    /* Merge Sorted Array */
    // LeetCode Problem 88
    // Easy level Problem

    // General Points :-

    // 1) This is based on 2-Pointers Approach.
    /* 2) The logic is to check from backwards using three variables
       (idx,i,j) and compare the elements of two arrays from those indices
       and store the elements in first array in ascending order. */
    // 3) Time complexity = O(N). => (N = m+n)
    // 4) Space complexity = O(1)

    int m, n;
    // Input m,n
    cout << "Enter the size of two arrays = ";
    cin >> m >> n;
    int size1 = m + n, size2 = n;
    // Input nums1
    cout << "\nEnter nums1 elements :\n";
    vector<int> nums1(size1); // E.g. => [1,2,3,0,0,0]
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter the elements at index " << i << " = ";
        cin >> nums1[i];
    }
    // Input nums2
    cout << "\nEnter nums2 elements :\n";
    vector<int> nums2(size2); // E.g. => [2,5,6]
    for (int j = 0; j < size2; j++)
    {
        cout << "Enter the elements at index " << j << " = ";
        cin >> nums2[j];
    }
    // Output
    printArrBef(nums1);
    mergeArr(nums1, nums2, m, n); // merged by function
    printArrAft(nums1);

    return 0;
}