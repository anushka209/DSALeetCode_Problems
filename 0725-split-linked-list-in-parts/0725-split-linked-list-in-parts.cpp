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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int size=0;
        ListNode* curr=head;
        while(curr!=NULL)     //total size of linked list
        {
            size++;
            curr=curr->next;
        }
        int splitSize=size/k;   //minimum size for k parts
        int numRem=size % k;
        curr=head;
        ListNode* prev=curr;
        for(int i=0;i<k;i++)
        {
            ListNode* newPart=curr;  //create ith part
            int currSize=splitSize;  //calculate size of ith part
            if(numRem>0)
            {
                numRem--;
                currSize++;
            }
            //traverse to end of new Part
            int j=0;
            while(j<currSize)
            {
                prev=curr;
                if(curr!=NULL)
                    curr=curr->next;
                j++;
            }
            //cut off rest of linked list
            if(prev!=NULL)
                prev->next=NULL;
            ans[i]=newPart;
        }
        return ans;
    }
};