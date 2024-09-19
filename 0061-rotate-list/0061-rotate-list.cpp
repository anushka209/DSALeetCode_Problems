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
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || k==0)
     return head;
      ListNode* tail=head;
      ListNode* temp=head;
      int len=1;
      while(tail->next!=NULL)
     {
          len++;
          tail=tail->next;
     }
     if(k%len==0)
          return head;
     else{
          k=k%len;
       tail->next=head;
     int num=len-k;
     num--;
     while (temp != NULL && num != 0) {
       num--;
       temp = temp->next;
     }
      head=temp->next;
     temp->next = NULL;
     }
     return head;
    }
};