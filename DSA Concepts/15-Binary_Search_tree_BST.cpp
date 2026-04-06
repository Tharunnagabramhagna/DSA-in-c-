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

void inorder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node *root, int key)
{ // T.C => O(Height) ; worst case => O(log n)
    // Edge Case
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    // Binary Search checking
    if (root->data > key)
        return search(root->left, key);
    else // (root->data < key)
        return search(root->right, key);
}

// getIS function => getInorderSuccessor function
Node *getIS(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// Delete any Node from a BST
Node *delNode(Node *root, int key)
{ // T.C => O(log n)
    // Step-1 : Find that node

    // Edge Case
    if (root == NULL)
        return NULL;

    if (root->data > key)
        root->left = delNode(root->left, key);
    else if (root->data < key)
        root->right = delNode(root->right, key);
    else
    { // delete case as (root == key)
        // Case-1 & Case-2 => if the Node has one (or) no children
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Case-3 => if the Node has more than one children
        Node *IS = getIS(root->right);                // 1)get the inorder successor
        root->data = IS->data;                        // 2)replace IS with curr node
        root->right = delNode(root->right, IS->data); // 3)delete the IS original place
    }
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = BuildBST(arr);
    cout << "Elements of BST in inorder(sorted) : \n";
    inorder(root);
    cout << endl;

    cout << "\n__Search in BST__\n";
    cout << "If the value exists, it returns 1 else 0.\n";
    cout << "Does 5 exist : " << search(root, 5) << endl;
    cout << "Does 8 exist : " << search(root, 8) << endl;

    cout << "\n__Delete Node in BST__\n";
    cout << "Before Deletion the inorder is : \n";
    inorder(root);
    cout << endl;
    delNode(root, 5);
    cout << "After Deletion the inorder is : \n";
    inorder(root);
    cout << endl;

    return 0;
}