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
    bool isPalindrome(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return true;

        //find the middle of the linked list
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr)        
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        //Reverse the linked list from the middle node

        ListNode* prev=nullptr;
        ListNode* current=slow;

        while(current!=nullptr)
        {
            ListNode* nextNode=current->next;

            current->next=prev;

            prev=current;

            current=nextNode;
        }

        //check for palindrome

        ListNode* left=head;
        ListNode* right=prev;

        while(right!=nullptr)
        {
            if(left->val!=right->val)
            {
                return false;
            }

            left=left->next;
            right=right->next;
        }

        return true;
        
    }
};