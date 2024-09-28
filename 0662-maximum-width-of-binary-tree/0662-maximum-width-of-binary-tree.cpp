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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,long>>q;      //to store node and index
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int min=q.front().second;       //to make the id starting from 0
            int first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                long curr=q.front().second-min;     //to update the index as 1,2,3,4.....so on...
                q.pop();
                if(i==0)  first=curr;
                if(i==size-1)  last=curr;
                if(node->left) 
                    q.push({node->left,2*curr+1});
                if(node->right)
                    q.push({node->right,2*curr+2});
            }
            ans=max(ans,static_cast<int>(last-first+1));
        }
        return ans;
    }
};