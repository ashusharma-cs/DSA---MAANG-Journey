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
    int pairSum(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* middleNode=slow;

        ListNode* prev=nullptr;
        ListNode* current=middleNode;

        while(current!=nullptr)
        {
            ListNode* nextNode=current->next;

            current->next=prev;

            prev=current;

            current=nextNode;
        }

        int maxSum=0;

        ListNode* left=head;
        ListNode* right=prev;

        while(right!=nullptr)
        {
            int sum=left->val+right->val;

            maxSum=max(maxSum,sum);

            left=left->next;
            right=right->next;
        }

        return maxSum;
        
    }
};