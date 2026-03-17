#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmallEl(vector<int> &arr1, stack<int> &s1, vector<int> &ans1)
{ // T.C = O(n)
    for (int i = 0; i < arr1.size(); i++)
    {
        while (s1.size() > 0 && s1.top() >= arr1[i])
            s1.pop();
        // no match found case
        if (s1.empty())
            ans1[i] = -1;
        else
            ans1[i] = s1.top();
        s1.push(arr1[i]);
    }
    return ans1;
}

vector<int> nxtGreater(vector<int> &arr, stack<int> &s, vector<int> &ans)
{ // T.C = O(n)
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= arr[i])
            s.pop();
        // no match found case
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

/* Celebrity Problem */
/* Given a 2D Array (nxn), such that arr[i][j] = 1 means the ith person knows jth person,
the task is to find the celebrity.
A clebrity is a person who is known to all but does not know anyone.
Return the index of the celebrity, if there is no celebrity return -1.

Ex :- arr = [[0,1,0],[0,0,0],[0,1,0]]*/

int getCelebrity(vector<vector<int>> &arr)
{
    int n = arr.size();
    stack<int> s;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (arr[i][j] == 0)
            s.push(i);
        else
            s.push(j);
    }

    int celeb = s.top();

    for (int i = 0; i < n; i++)
    {
        if ((i != celeb) &&
            (arr[i][celeb] == 0 || arr[celeb][i] == 1))
            return -1;
    }

    return celeb;
}

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    nxtGreater(arr, s, ans);

    cout << "Values of the next greater elements : \n";
    for (int a : ans)
        cout << a << " ";
    cout << endl;

    // Previous small element question
    vector<int> arr1 = {3, 1, 0, 8, 6};
    stack<int> s1;
    vector<int> ans1(arr1.size(), 0);

    prevSmallEl(arr1, s1, ans1);

    cout << "Values of the previous small elements : \n";
    for (int a : ans1)
        cout << a << " ";
    cout << endl;

    // Celebrity Problem
    vector<vector<int>> arr2 = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int res = getCelebrity(arr2);

    cout << "Celebrity is : " << res << endl;

    return 0;
}