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
    int find_sum(TreeNode* root,int& sum)
    {
        if(root==NULL)
            return 0;
        int l=max(0,find_sum(root->left,sum));    //to avoid take negative sum that's why we take max of 0,.....
        int r=max(0,find_sum(root->right,sum));
        sum=max(sum,root->val+l+r);
        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
       int sum=INT_MIN;
       find_sum(root,sum);
       return sum;
    }
};