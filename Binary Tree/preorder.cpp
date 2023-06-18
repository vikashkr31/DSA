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

//Recursive

void preOrder(TreeNode *root)
{
    if(root == NULL)
        return;

    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//Iterative

vector<int> preOrderIterative(TreeNode *root)
{
    vector<int> preOrder;
    if(root = NULL) 
        return preOrder;

    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty())
    {
        TreeNode *top = stk.top();
        stk.pop();
        preOrder.push_back(top->val);
        if(top->right)
            stk.push(top->right);
        if(top->left)
            stk.push(top->left);
    }

    return preOrder;
}