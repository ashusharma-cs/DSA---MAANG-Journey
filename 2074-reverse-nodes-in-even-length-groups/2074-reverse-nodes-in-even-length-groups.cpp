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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* groupPrev=dummy;

        int k=1;

        while(groupPrev->next!=nullptr)
        {
            int count=0;
            ListNode* current=groupPrev->next;

            while(count<k && current!=nullptr)
            {
                count++;
                current=current->next;
            }

            if(count%2==0)
            {
                ListNode* prev=current;
                ListNode* currentNode=groupPrev->next;

                for(int i=0;i<count;i++)
                {
                    ListNode* nextNode=currentNode->next;
                    currentNode->next=prev;
                    prev=currentNode;
                    currentNode=nextNode;
                }

                ListNode* tmp=groupPrev->next;
                groupPrev->next=prev;
                groupPrev=tmp;
            }
            else
            {
                for(int i=0;i<count;i++)
                {
                    groupPrev=groupPrev->next;
                }
            }
            
            k++;

        }

        return dummy->next;
    }
};