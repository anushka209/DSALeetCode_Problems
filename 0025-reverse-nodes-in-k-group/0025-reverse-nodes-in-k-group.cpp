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

ListNode* findKNode(ListNode* temp,int k)
{
    k--;
    while (temp!=NULL && k != 0) 
    {
        k--;
      temp = temp->next;
    }
    return temp;
}

ListNode* reverse(ListNode* head)
{
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL)
    {
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* temp=head;
     ListNode *prevNode = NULL;
    while (temp != NULL)
     {
        ListNode *kNode = findKNode(temp, k);
        if(kNode==NULL)
        {
           if(prevNode) prevNode->next=temp;
            break;
        }
        ListNode *nextNode = kNode->next;
        kNode->next = NULL;
        reverse(temp);
        if(temp==head)
            {
                head=kNode;
        } 
        else {
            prevNode->next=kNode;
        }
            prevNode = temp;
            temp = nextNode;
    }
    return head;
    }
};