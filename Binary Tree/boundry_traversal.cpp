#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *node)
{
    return ((node->left == NULL) && (node->right == NULL));
}

void leftNodes(TreeNode *root, vector<int> &res)
{
    if(isLeaf(root)) return;

    if(root->left)
    {
        res.push_back(root->val);
        leftNodes(root->left,res);
    }
    else if(root->right)
    {
         res.push_back(root->val);
         leftNodes(root->right,res);
    }
}

void rightNodes(TreeNode *root, vector<int> &res)
{
    if(isLeaf(root)) return;

    if(root->right)
    {
        rightNodes(root->right,res);
        res.push_back(root->val);
    }
    else if(root->left)
    {
         rightNodes(root->left,res);
         res.push_back(root->val);
    }
}

void leafNodes(TreeNode *root, vector<int> &res)
{
    if(root == NULL) return;

    leafNodes(root->left, res);
    if(isLeaf(root))
        res.push_back(root->val);
    leafNodes(root->right, res);

}

vector<int> boundryTraversal(TreeNode *root)
{
    vector<int> res;
    if(root == NULL) return res;
    res.push_back(root->val);
    leftNodes(root->left, res);
    leafNodes(root, res);
    rightNodes(root->right, res);

    return res;

}