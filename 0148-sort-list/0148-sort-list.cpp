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

    ListNode* findmiddle(ListNode* head)
{
	ListNode* slow=head;
	ListNode* fast=head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

ListNode* mergeTwoList(ListNode* list1,ListNode* list2)
{
	ListNode* dummy=new ListNode(-1);
	ListNode* temp=dummy;
	ListNode* t1=list1;
	ListNode* t2=list2;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->val < t2->val)
		{
			temp->next=t1;
			temp=t1;
			t1=t1->next;
		}
		else{
			temp->next=t2;
			temp=t2;
			t2=t2->next;
		}
	}
	if(t1)
		temp->next=t1;                     //instead of traversal we picked up these elements
	else
		temp->next=t2;
		return dummy->next;
}

    ListNode* sortList(ListNode* head) {
      if(head==NULL || head->next==NULL)
	    return head;
	ListNode* middle=findmiddle(head);
	ListNode* leftHead=head;
	ListNode* rightHead=middle->next;
	middle->next=nullptr;

	leftHead=sortList(leftHead);
	rightHead=sortList(rightHead);
	return mergeTwoList(leftHead,rightHead);
    }
};