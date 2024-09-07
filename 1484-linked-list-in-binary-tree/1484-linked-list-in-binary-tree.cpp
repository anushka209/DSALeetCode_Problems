/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head,ListNode* curr,TreeNode* root)
    {
        if(curr==NULL) return true;     //match the list
        if(root==NULL) return false;     //reach end of tree without matching

        if(curr->val == root->val)   //move to next node if value matches
            curr=curr->next;
        else if(head->val==root->val)  // start new matching if value matches head of list
            head=head->next;
        else
            curr=head;    // reset matching pointer
        return dfs(head,curr,root->left) || dfs(head,curr,root->right);  //for check left and right subtree
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,head,root);
    }
};