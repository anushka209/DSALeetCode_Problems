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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int topR=0,bottomR=m-1,leftCol=0,rightCol=n-1;
        while(head)
        {
            for(int col=leftCol;col<=rightCol && head;col++)    // for top row
            {
                ans[topR][col]=head->val;
                head=head->next;
            }
            topR++;
            for(int row=topR;row<=bottomR && head;row++)          //for right column
            {
                ans[row][rightCol]=head->val;
                head=head->next;
            }
            rightCol--;
            for(int col=rightCol;col>=leftCol && head;col--)
            {
                ans[bottomR][col]=head->val;
                head=head->next;
            }
            bottomR--;
            for(int row=bottomR;row>=topR && head;row--)
            {
                ans[row][leftCol]=head->val;
                head=head->next;
            }
            leftCol++;
        }
        return ans;
    }
};