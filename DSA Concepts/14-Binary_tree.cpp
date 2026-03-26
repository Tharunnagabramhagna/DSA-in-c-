#include <iostream>
#include <vector>
using namespace std;

static int idx = -1; // to traverse the preorder vector

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // initializer list => new way of constructor initializing
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Create a Bulid Tree Recursive function
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

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = BuildTree(preorder);
    cout << "ROOT : " << root->data << endl;
    cout << "ROOT Left Child : " << root->left->data << endl;
    cout << "ROOT Right Child : " << root->right->data << endl;
    cout << "Right's Left Child : " << root->right->left->data << endl;
    cout << "Right's Right Child : " << root->right->right->data << endl;

    return 0;
}

// structure we bulid from preorder vector is :
//         1
//      2     3
// NULL NULL 4  5
//     NULL NULL NULL NULL

// Understanding the above structure :
// 1 is linked to 2 and 3 (2 <=> 1 <=> 3)
// 3 is linked to 4 and 5 (4 <=> 3 <=> 5)
// 2 is linked to two NULL pointers (NULL <=> 2 <=> NULL)
// 4 and 5 are same as 2 (NULL <=> 4 <=> NULL) (NULL <=> 5 <=> NULL)