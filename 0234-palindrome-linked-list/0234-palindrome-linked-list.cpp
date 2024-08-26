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
 #include<stack>
class Solution {
public:

// ListNode* reverse(ListNode* head)      //recursive reverse function
// {
//     if(head==NULL || head->next==NULL)
//         return head;
//     ListNode* newHead=reverse(head->next);
//     ListNode* front=head->next;
//     front->next=head;
//     head->next=nullptr;
//     return newHead;
// }

ListNode* reverse(ListNode* head)   //iterative reverse function
{
    if(head==NULL ||head->next==NULL)
        return head;
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

    bool isPalindrome(ListNode* head) {
    // stack<int>s;
    // ListNode* temp=head;
    // while(temp!=NULL)
    // {
    //     s.push(temp->val);
    //     temp=temp->next;
    // }
    // temp=head;
    // while(temp!=NULL)
    // {
    //     if(temp->val!= s.top())
    //      return false;
    //    else
    //    {
    //        temp=temp->next;
    //        s.pop();
    //    }
    // }
    // return true;

                                         //tortoise and hare then reverse the link & compare
    if(head==NULL || head->next==NULL)
        return true;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* newHead=reverse(slow->next);   // reverse the second half part
    ListNode* first=head;
    ListNode* second=newHead;
    while(second!=NULL)
    {
        if(first->val!=second->val)
        {
            reverse(newHead);     //make sure before return, back to original data.
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newHead);
    return true;
    }
};