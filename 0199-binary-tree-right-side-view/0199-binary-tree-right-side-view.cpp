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
    void rev_preorder(TreeNode* root,int level,vector<int>& ans)
    {
        if(root==NULL)  return;             //we do reverse preorder ie. root right left
        if(level==ans.size())
            ans.push_back(root->val);
        rev_preorder(root->right,level+1,ans);
        rev_preorder(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
      vector<int>ans;
      rev_preorder(root,0,ans);
      return ans;
    }
};