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
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* groupPrev=dummy;

        while(groupPrev->next!=nullptr && groupPrev->next->next!=nullptr)
        {
            ListNode* current=groupPrev->next;
            
            ListNode* kth=groupPrev->next->next;
            ListNode* groupNext=kth->next;

            ListNode* prev=groupNext;;

            while(current!=groupNext)
            {
                ListNode* nextNode=current->next;
                current->next=prev;
                prev=current;
                current=nextNode;
            }

            ListNode* tmp=groupPrev->next;
            groupPrev->next=kth;
            groupPrev=tmp;
        }

        return dummy->next;
        
    }
};