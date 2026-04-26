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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* runnerA=headA;
        ListNode* runnerB=headB;

        while(runnerA!=runnerB)
        {
           
            if(runnerA==nullptr)
            {
                runnerA=headB;
            }
            else
            {
                runnerA=runnerA->next;
            }

            
            if(runnerB==nullptr)
            {
                runnerB=headA;
            }
            else
            {
                runnerB=runnerB->next;
            }
        }

        return runnerA;

        
    }
};