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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* temp = &dummy;
        ListNode *nxt, *prev = NULL;
        int limit = right - left + 1;
        ListNode* tempB4=temp;
        while (left--) {
            tempB4=temp;
            temp = temp->next;
        }
        
        while(limit--){
            nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        
        tempB4->next->next=temp;
        tempB4->next=prev;

        return dummy.next;
    }
};