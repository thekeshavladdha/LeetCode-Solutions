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
        ListNode* fast=head;
        ListNode* slow=head;
        
        if(fast->next==NULL) return true;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;
        fast=head;
        
        ListNode* temp,*prev=slow;
        slow=slow->next;
        prev->next =nullptr;
        
        while(slow!=NULL){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        slow=prev;
        while(slow!=nullptr){
            if(fast->val!=slow->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;

        
    }
};