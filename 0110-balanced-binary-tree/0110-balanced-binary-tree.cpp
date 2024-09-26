/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find_height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh=find_height(root->left);
        if(lh==-1) return -1;             //any subtree is unbalanced, If the left subtree is unbalanced, propagate the unbalance status
        int rh=find_height(root->right);
        if(rh==-1) return -1;             //any subtree is unbalanced, If the right subtree is unbalanced, propagate the unbalance status
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return find_height(root)!=-1;
    }
};