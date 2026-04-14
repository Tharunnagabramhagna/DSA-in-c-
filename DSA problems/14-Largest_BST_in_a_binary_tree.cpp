#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), right(NULL), left(NULL) {}
};

class Info
{
public:
    int min, max, sz;
    Info(int m, int M, int s) : min(m), max(M), sz(s) {}
};

Info helper(Node *root)
{
    // Base case
    if (root == NULL)
        return Info(INT_MAX, INT_MIN, 0);
    Info left = helper(root->left);
    Info right = helper(root->right);
    // For a valid BST
    if (root->data > left.max && root->data < right.min)
    {
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.sz + right.sz + 1;
        return Info(currMin, currMax, currSz);
    }
    return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
}

int largestBSTInBT(Node *root)
{
    Info info = helper(root);
    return info.sz;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    cout << "Size of largest BST in binary tree is " << largestBSTInBT(root) << endl;

    return 0;
}