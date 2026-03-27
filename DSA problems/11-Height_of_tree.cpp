#include <iostream>
#include <vector>
using namespace std;

static int idx = -1;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Create a Build Tree Recursive function
Node *BuildTree(vector<int> preorder)
{
    idx++;

    // Base Case
    if (preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);
    root->left = BuildTree(preorder);  // Left sub-tree
    root->right = BuildTree(preorder); // Right sub-tree
    return root;
}
// Height of the Tree
int height(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return (max(leftHt, rightHt) + 1);
}
// Count of Nodes of the Tree
int count(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}
// Sum of Nodes in a Tree
int sumNodes(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = BuildTree(preorder);

    cout << "Height of the Tree : " << height(root) << endl;
    cout << "Count of the Tree : " << count(root) << endl;
    cout << "Sum of the Tree : " << sumNodes(root) << endl;
    return 0;
}