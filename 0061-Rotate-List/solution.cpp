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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL) return head;
        
        int count=1;
        ListNode* end=head;
        while(end->next!=NULL){
            count++;
            end=end->next;
        }
        k=k%count;
        if(k==0) return head;
        end->next=head;
        ListNode* ptr=head;
        count-=k;
        while(true){
            if(count==1) break;
            ptr=ptr->next;
            count--;
        }
        end=ptr->next;
        ptr->next=NULL;
        head=end;
        return head;
    }

};