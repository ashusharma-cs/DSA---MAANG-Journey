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
    ListNode* getKth(ListNode* curr, int k) {
        for (int i = 0; i < k; i++) {
            if (curr == nullptr) {
                break;
            }

            curr = curr->next;
        }

        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        

        while (true) 
        {
            
            ListNode* kth = getKth(groupPrev, k);

            if(kth==nullptr) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;

            ListNode* current=groupPrev->next;

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