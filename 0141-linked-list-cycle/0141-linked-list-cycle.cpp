/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    ListNode* slow=head;             
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)    //for linear LL
    {
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast)       //loop condition
        return true;
    }
    return false;
    }
};