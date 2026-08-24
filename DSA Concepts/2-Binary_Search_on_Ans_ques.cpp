#include <iostream>
#include <climits>
#include <algorithm> // for sorting
#include <vector>
using namespace std;

/*The Book Allocation Problem is a classic algorithmic challenge, frequently encountered
in competitive programming and technical interviews. It is a prime example of the Binary
Search on Answer technique.*/

/* The Problem Statement //
Given n number of books and m number of students.Every book has a specific number of pages.
You are required to allocate these books to the m students such that,Every student gets at
least one book.Each book should be allocated to only one student.All books must be allocated.
The allocation must be in a contiguous manner. For example, if a student is assigned books,
they must be books that appear next to each other in the given list.Return '-1' if a valid
assignment is not possible. */
/* The Objective //
Your goal is to assign books in such a way that the maximum number of pages
assigned to a student is minimized. */

bool isValid(vector<int> &arr, int m, int maxAllocatedPages)
{ // O(n)
    int student = 1, pages = 0, i;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxAllocatedPages)
            return false;
        if (pages + arr[i] <= maxAllocatedPages)
            pages += arr[i];
        else
        {
            student++;
            pages = arr[i];
        }
    }
    return (student > m) ? false : true;
    // false => invalid ; true => valid
}

int allocateBook(vector<int> &arr, int m)
{
    // Edge case
    if (arr.size() < m)
        return -1;
    // sum of elements
    int sum = 0, st = 0;
    // start from max array value because smaller values are not a possible answers
    for (int val : arr) {// O(n)
        st = max(st,val);
        sum += val;
    }

    int end = sum, ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, m, mid))
        {
            // Valid Case => search in left half
            ans = mid;
            end = mid - 1;
        }
        else
            // Invalid case => search in right half
            st = mid + 1;
    }
    return ans;
}

/* The Painter's Partition Problem is an optimization challenge where you must divide a
set of contiguous boards (represented by lengths) among a fixed number of painters (k))
to minimize the total time taken, with each painter handling a continuous segment and
taking time proportional to board length. The goal is to find the smallest possible
maximum time any single painter spends, often solved using binary search on the potential
time range. */

/* The Painter's Partition Problem asks for the minimum time to paint 'n' boards with
lengths given in an array, using 'k' painters, where each painter paints continuous
board sections, and 1 unit of board takes 1 unit of time; the goal is to minimize
the maximum time any single painter works, ensuring all boards are painted.  */

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{ // O(n)
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedTime)
            return false;
        if (time + arr[i] <= maxAllowedTime)
            time += arr[i];
        else
        {
            painters++;
            time = arr[i];
        }
    }
    return (painters <= m) ? true : false;
    // false => invalid ; true => valid
}

int painterPartition(vector<int> &arr, int m)
{
    int n = arr.size();
    // sum of elements
    int end = 0, maxVal = INT_MIN;
    for (int val : arr) {// O(n)
        // max element
        maxVal = max(maxVal, val);
        end += val;
    }

    int st = maxVal, ans = -1;
    while (st <= end) // O(log sum)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(arr, n, m, mid))
        {
            // Valid Case => search in left half
            ans = mid;
            end = mid - 1;
        }
        else
            // Invalid case => search in right half
            st = mid + 1;
    }
    return ans;
}
/* The Aggressive Cows problem asks you to place K cows in N stalls
(given as an array of positions on a line) such that the minimum
distance between any two cows is maximized, and then return this
largest possible minimum distance. It's a classic optimization problem
often solved using binary search on the answer, checking if a given minimum
distance is feasible.  */

bool isCorrect(vector<int> &arr, int n, int c, int maxAllowedDistance)
{
    int cows = 1, lastStallPos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - lastStallPos) >= maxAllowedDistance)
        {
            cows++;
            lastStallPos = arr[i];
        }
        if (cows == c)
            return true;
    }
    return false;
}

int getDistance(vector<int> &arr, int c)
{
    int n = arr.size();
    // Edge Case
    if (n < c)
        return -1;
    // Sorting the array
    sort(arr.begin(), arr.end());
    // After sorting largest value is in n-1 and smallest in 0 indices.
    int st = 1, end = arr[n - 1] - arr[0], ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isCorrect(arr, n, c, mid))
        { // right search
            ans = mid;
            st = mid + 1;
        }
        else // left search
            end = mid - 1;
    }
    return ans;
}

int main()
{
    /* Book Allocation Problem */

    // General Points :-
    // 1) if the number of students are more the number of books return '-1'.
    // 2) let, st = 0,end = sum(arr),ans = -1.
    // 3) This code is based on binary search algorithm (modified).
    // 4) if mid is valid search in left half (if case). => end = mid - 1
    // 5) if mid is invalid search in right half (else case). => st = mid + 1
    // 6) The vadility of mid is checked using a function names isValid.
    // 7) Time Complexity = O(n * log (sum))
    // 7) Space Complexity = O(1)

    cout << "___ Book Allocation ___" << endl;
    int n, m;
    // input size
    cout << "Enter the size of Array = ";
    cin >> n;
    // input arr
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at index " << i << " = ";
        cin >> arr[i];
    }
    // input students
    cout << "Enter the number of students required = ";
    cin >> m;
    // output
    cout << "Minimum number of pages = " << allocateBook(arr, m) << endl;

    /* Painter's Parition Problem */

    // General Points :-
    // 1) This is a problem based on book allocation.
    // 2) This is similar to book allocation just a small change is done.
    // 3) st = min(arr) value to get the minimum time taken.

    cout << "___ Painter's Parition Problem ___" << endl;
    int n1, m1;
    // input size
    cout << "Enter the size of Array = ";
    cin >> n1;
    // input arr
    vector<int> Arr(n1);
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter the element at index " << i << " = ";
        cin >> Arr[i];
    }
    // input students
    cout << "Enter the number of painters required = ";
    cin >> m1;
    // output
    cout << "Minimum amount of time = " << painterPartition(Arr, m1) << endl;

    /* Aggressive Cows Problem */

    // General Points :-

    // 1) The given array should have atleast 2 cows.
    // 2) This is also based on book allocation problem.
    // 3) let, st = low and end = high.
    // 4) Answer should be the largest possible minimum distance.
    // 5) The lowest value for minimum distance = 1.
    // 6) Highest possible distance = largest el - smallest el in array.
    // 7) if mid is possible then search in right half else in left half.

    cout << "___ Aggressive Cows Problem ___" << endl;
    int n2, c;
    // input size
    cout << "Enter the size of Array = ";
    cin >> n2;
    // input arr
    vector<int> Vec(n2);
    for (int i = 0; i < n2; i++)
    {
        cout << "Enter the element at index " << i << " = ";
        cin >> Vec[i];
    }
    // input cows
    cout << "Enter the number of cows required = ";
    cin >> c;
    // output
    cout << "largest possible Minimum distance = " << getDistance(Vec, c) << endl;

    return 0;
}