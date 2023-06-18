#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSum(TreeNode *root, int &maxSum)
{
    if(root == NULL)
        return 0;

    int lSum = maxPathSum(root->left, maxSum);
    int rSum = maxPathSum(root->right, maxSum);
    maxSum = max(maxSum, lSum+rSum+root->val);

    return max(lSum,lSum)+root->val;
}