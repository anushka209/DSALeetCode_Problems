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
    void preorder(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        preorder(root,res);
        return res;

        // if(root==NULL)  return res;
        // stack<TreeNode*>st;
        // st.push(root);
        // while(!st.empty())
        // {
        //     root=st.top();
        //     st.pop();
        //     res.push_back(root->val);
        //     if(root->right!=NULL) st.push(root->right);
        //     if(root->left!=NULL) st.push(root->left);
        // }
        // return res;

 //  ------------------MORRIS TRAVERSAL----------------------------------------
        // vector<int>preorder;
        // TreeNode* curr=root;
        // while(curr!=NULL)
        // {
        //     if(curr->left==NULL) 
        //     {
        //         preorder.push_back(curr->val);
        //         curr=curr->right;
        //     }
        //     else
        //     {
        //         TreeNode* prev=curr->left;
        //         while(prev->right && prev->right!=curr)
        //         {
        //             prev=prev->right;
        //         }
        //         if(prev->right==NULL){
        //             prev->right=curr;
        //             preorder.push_back(curr->val);
        //             curr=curr->left;
        //         }
        //         else{
        //             prev->right=NULL;
        //             curr=curr->right;
        //         }
        //     }
        // }
        // return preorder;
    }
};