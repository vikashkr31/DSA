#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int isBalanced(TreeNode *root)
{
    if(root == NULL) return 0;

    int lHeight = isBalanced(root->left);
    if(lHeight == -1) return -1;
    int rHeight = isBalanced(root->right);
    if(rHeight == -1) return -1;

    if(abs(lHeight-rHeight)>1)
        return -1;

    return 1+ max(lHeight, rHeight);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->left->left = new TreeNode(3);
    cout<<isBalanced(root);

    return 0;
}