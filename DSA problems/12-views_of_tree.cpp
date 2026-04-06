#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Create a Build Tree Recursive function
Node *BuildTree(const vector<int> &preorder, int &idx)
{
    idx++;

    // Base Case
    if (idx >= (int)preorder.size() || preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);
    root->left = BuildTree(preorder, idx);  // Left sub-tree
    root->right = BuildTree(preorder, idx); // Right sub-tree
    return root;
}

void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// HD => Horizontal Distance
void topView(Node *root)
{ // O(n log n)
    if (!root)
        return;
    queue<pair<Node *, int>> q; // pair => [Node, HD]
    map<int, int> m;            // [HD, node val]

    q.push({root, 0});
    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        // pushing nodes and HD to map
        if (m.find(currHD) == m.end()) // O(log n)
            m[currHD] = curr->data;
        if (curr->left != NULL)
            q.push({curr->left, currHD - 1});
        if (curr->right != NULL)
            q.push({curr->right, currHD + 1});
    }
    // printing the final values of top-view
    for (auto i : m)
        cout << i.second << " ";
    cout << endl;
}

void bottomView(Node *root)
{
    if (root == NULL)
        return;

    queue<pair<Node *, int>> q;
    map<int, int> m;

    q.push({root, 0});
    while (!q.empty())
    {
        Node *curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        // overwrite existing values to get the bottom-most node at each HD
        m[currHD] = curr->data;
        if (curr->left != NULL)
            q.push({curr->left, currHD - 1});
        if (curr->right != NULL)
            q.push({curr->right, currHD + 1});
    }

    for (auto i : m)
        cout << i.second << " ";
    cout << endl;
}

// Kth level of the Tree Question
void KthLevel(Node *root, int k)
{
    // Edge Case
    if (root == NULL)
        return;
    // Base Case
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    KthLevel(root->left, k - 1);
    KthLevel(root->right, k - 1);
}

// Transform to Sum Tree
int sumTree(Node *root)
{ // O(n)
    // Base Case
    if (root == NULL)
        return 0;
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum + rightSum;
    return root->data;
}

int main()
{
    // Top and Bottom Views of the Tree
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = BuildTree(preorder, idx);
    cout << "Top View Nodes of the Binary Tree : \n";
    topView(root); // 2 1 3 5
    cout << "Bottom View Nodes of the Binary Tree : \n";
    bottomView(root); // 2 4 3 5

    // Kth Level of the Tree
    vector<int> preorder1 = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node *root1 = BuildTree(preorder1, idx);
    cout << "Nodes of Kth Level of the tree : \n";
    KthLevel(root1, 3);
    cout << endl;

    // Sum Tree
    vector<int> preorder2 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node *root2 = BuildTree(preorder2, idx);
    cout << "Before Conversion of Tree : ";
    PreOrder(root2);
    cout << endl;

    sumTree(root2);

    cout << "After Conversion of Tree to Sum Tree : ";
    PreOrder(root2);
    cout << endl;

    return 0;
}