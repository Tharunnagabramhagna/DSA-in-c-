#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* rightMostinLeftSubTree(Node* root) {
    Node* ans;
    
    while(root != NULL) {
        ans = root;
        root = root->right;
    }

    return ans;
}

Node* leftMostinRightSubTree(Node* root) {
    Node* ans;
    
    while(root != NULL) {
        ans = root;
        root = root->left;
    }

    return ans;
}

vector<int> getPredSucc(Node *root, int key)
{
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL) {
        if(key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else { // (key == curr->data) 
            if(curr->left != NULL)
            pred = rightMostinLeftSubTree(curr);

            if(curr->right != NULL)
            succ = leftMostinRightSubTree(curr);

            break;
        }
    }

    return {pred->data, succ->data};
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    int key = 7;
    vector<int> ans = getPredSucc(root, key);
    cout << "Predecessor value : " << ans[0] << endl;
    cout << "Successor value : " << ans[1] << endl;

    return 0;
}