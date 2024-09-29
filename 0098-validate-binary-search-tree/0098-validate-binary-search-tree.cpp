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
void inorder(TreeNode* root,vector<int> &ans)
{
    if(root==NULL)  return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]<=ans[i-1])
                return false;
        }
        return true;

       // return checkValid(root,INT_MIN,INT_MAX);
    }

    // bool checkValid(TreeNode* root,long mini,long maxi)
    // {
    //     if(root==NULL)  return true;
    //     if(root->val>=maxi || root->val<=mini)  return false;
    //     return checkValid(root->left,mini,root->val) && checkValid(root->right,root->val,maxi);
    // }
};