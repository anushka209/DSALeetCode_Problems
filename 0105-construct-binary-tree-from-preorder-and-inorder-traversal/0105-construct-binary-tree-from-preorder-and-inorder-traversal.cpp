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
   TreeNode* createTree(vector<int>& preorder,int pstart,int pend,vector<int>& inorder,int istart,int iend,map<int,int>& mpp)
   {
        if(pstart>pend || istart>iend)
            return NULL;
        TreeNode* root=new TreeNode(preorder[pstart]);
        int iRoot=mpp[root->val];
        int numLeft=iRoot-istart;

        root->left=createTree(preorder,pstart+1,pstart+numLeft,inorder,istart,iRoot-1,mpp);
        root->right=createTree(preorder,pstart+numLeft+1,pend,inorder,iRoot+1,iend,mpp);
        return root;
   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      map<int,int>mpp;
      for(int i=0;i<inorder.size();i++)
      {
        mpp[inorder[i]]=i;
      }
      TreeNode* root=createTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
      return root;
    }
};