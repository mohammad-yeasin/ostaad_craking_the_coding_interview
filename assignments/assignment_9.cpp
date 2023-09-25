// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printPreOrder(TreeNode* root)
{
    // base case
    if(root == nullptr) return;
    // recursive case
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

/*
    Average Case Time Complexity: O(h)
    Worst Case Time Complexity (skewed tree): O(n)
    Space Complexity (average case): O(h)
    Space Complexity (worst case, skewed tree): O(n)
*/
TreeNode* searchInBST(TreeNode* root, int inp)
{
    // base case
    if(root == nullptr) return nullptr;
    if(root->val == inp) return root;
    // recursive case
    if(root->val > inp) return searchInBST(root->left, inp);
    return searchInBST(root->right, inp);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    TreeNode* res = searchInBST(root, 5);
    printPreOrder(res);

    return 0;
}
