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

int treeDimeter(TreeNode *root, int &dimeter)
{
    if(root == NULL)
        return 0;

    int lh = treeDimeter(root->left, dimeter);
    int rh = treeDimeter(root->right, dimeter);
    dimeter = max(dimeter, lh+rh);

    return 1+max(lh,rh);
}
