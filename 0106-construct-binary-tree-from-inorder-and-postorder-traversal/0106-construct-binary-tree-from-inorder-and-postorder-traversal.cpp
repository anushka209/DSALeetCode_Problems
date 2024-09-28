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
    TreeNode* createTree(vector<int>& inorder,int istart,int iend,vector<int>& postorder,int pstart,int pend,map<int,int>& mpp)
    {
        if(pstart>pend || istart>iend)  return NULL;
        TreeNode* root=new TreeNode(postorder[pend]);
        int iRoot=mpp[root->val];
        int numLeft=iRoot-istart;

        root->left=createTree(inorder,istart,iRoot-1,postorder,pstart,pstart+numLeft-1,mpp);
        root->right=createTree(inorder,iRoot+1,iend,postorder,pstart+numLeft,pend-1,mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       if(inorder.size()!=postorder.size())
            return NULL;
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode* root=createTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};