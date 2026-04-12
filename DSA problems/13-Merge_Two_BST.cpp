#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int val)
{
    // Base Case
    if (root == NULL)
        return new Node(val);

    // Recursive Case
    if (val < root->data)
        root->left = insert(root->left, val);
    else // (val > root->data)
        root->right = insert(root->right, val);

    return root; // Final Call
}

Node *BuildBST(vector<int> &arr)
{
    Node *root = NULL;
    for (int val : arr)
        root = insert(root, val);
    return root;
}

void inorder(Node *root, vector<int> &arr1)
{
    // Base Case
    if (root == NULL)
        return;
    inorder(root->left, arr1);
    arr1.push_back(root->data);
    inorder(root->right, arr1);
}

Node *BuildBSTSorted(vector<int> &arr, int st, int end)
{
    // Base Case
    if (st > end)
        return NULL;
    int mid = st + (end - st) / 2;
    Node *root = new Node(arr[mid]);
    root->left = BuildBSTSorted(arr, st, mid - 1);
    root->right = BuildBSTSorted(arr, mid + 1, end);
    return root;
}

Node *mergeTrees(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    vector<int> temp; // takes both BST'S in a sorted order

    int i = 0, j = 0; // keep track of pushing el to temp
    // To add the Sorted elements in the temp
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
            temp.push_back(arr1[i++]);
        else
            temp.push_back(arr2[j++]);
    }
    // To add the remaining leftovers in temp
    while (i < arr1.size())
        temp.push_back(arr1[i++]);
    while (j < arr2.size())
        temp.push_back(arr2[j++]);
    return BuildBSTSorted(temp, 0, temp.size() - 1);
}

int main()
{

    vector<int> arr1 = {2, 1, 8, 10};
    vector<int> arr2 = {0, 3, 5};

    Node *root1 = BuildBST(arr1);
    Node *root2 = BuildBST(arr2);

    Node *root = mergeTrees(root1, root2);

    cout << "Inorder traversal of merged BST: ";
    vector<int> seq;
    inorder(root, seq);
    for (int v : seq)
        cout << v << " ";
    cout << endl;

    return 0;
}