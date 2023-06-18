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

int treeDiameter(TreeNode *root, int &diameter)
{
    if(root == NULL)
        return 0;

    int lh = treeDiameter(root->left, diameter);
    int rh = treeDiameter(root->right, diameter);
    diameter = max(diameter, lh+rh);

    return 1+max(lh,rh);
}
