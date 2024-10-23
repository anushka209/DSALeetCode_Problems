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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>currSum;
        q.push(root);
        while(!q.empty())
        {
            int sum=0;
            int n=q.size();
            while(n--)
            {
            TreeNode* node=q.front();
            q.pop();
            sum+=node->val;
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            }
            currSum.push_back(sum);
        }
        q.push(root);
        root->val=0;
        int i=1;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
            TreeNode* node=q.front();
            q.pop();
            int siblingSum=node->left!=NULL ? node->left->val : 0;
            siblingSum+=node->right!=NULL ? node->right->val : 0;
            if(node->left!=NULL)
            {
                node->left->val=currSum[i]-siblingSum;
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                node->right->val=currSum[i]-siblingSum;
                q.push(node->right);
            }   
            }
            i++;
        }
        return root;
    }
};