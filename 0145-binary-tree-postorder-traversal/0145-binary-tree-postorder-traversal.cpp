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
    void postorder(TreeNode* root, vector<int>& res)
    {
        if(root==NULL) return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        postorder(root,res);
        return res;
        // ---------------------------------------------
        // if(root==NULL) return res;
        // stack<TreeNode*>st1,st2;
        // st1.push(root);
        // while(!st1.empty())
        // {
        //     root=st1.top();
        //     st1.pop();
        //     st2.push(root);
        //     if(root->left!=NULL) st1.push(root->left);
        //     if(root->right!=NULL) st1.push(root->right); 
        // }
        // while(!st2.empty())
        // {
        //     res.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return res;
        // ----------------------------------

        // stack<TreeNode*>st;
        // TreeNode* curr=root;
        // TreeNode* temp=NULL;
        // st.push(curr);
        // while(curr!=NULL || !st.empty())
        // {
        //     if(curr!=NULL)
        //     {
        //         st.push(curr);
        //         curr=curr->left;
        //     }
        //     else
        //     {
        //          temp=st.top()->right;
        //          if(temp==NULL)
        //          {
        //             temp=st.top();
        //             st.pop();
        //             res.push_back(temp->val);
        //             while(!st.empty() && temp==st.top()->right)
        //             {
        //                 temp=st.top();
        //                 st.pop();
        //                 res.push_back(temp->val);
        //             }
        //          }
        //          else
        //             curr=temp;
        //     }
        // }
        // return res;
    }
};