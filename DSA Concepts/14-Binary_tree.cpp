#include <iostream>
#include <vector>
#include <queue>
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

// Traversals => preorder, inorder, postorder, level order (iterative)
// starting 3 algorithms are recursive functions

// 1) preorder traversal
void Preorder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// 2) inorder traversal
void inorder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 2) postorder traversal
void postorder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 3) Level-Order traversal (DFS)
void levelOrder(Node *root)
{
    queue<Node *> q;
    // step-1 => push to queue
    q.push(root);
    q.push(NULL);
    // step-2 => pop each level of tree
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
                break;
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
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
    cout << "Elements of the Binary Tree (Post order) : \n";
    Preorder(root);
    cout << endl;
    cout << "Elements of the Binary Tree (In order) : \n";
    inorder(root);
    cout << endl;
    cout << "Elements of the Binary Tree (Post order) : \n";
    postorder(root);
    cout << endl;
    cout << "Elements of the Binary Tree (Level order => DFS) : \n";
    levelOrder(root);
    cout << endl;

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