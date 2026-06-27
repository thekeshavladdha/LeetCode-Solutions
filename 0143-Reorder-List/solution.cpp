class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* rev = nullptr;
        while (mid) {
            ListNode* next = mid->next;
            mid->next = rev;
            rev = mid;
            mid = next;
        }
        ListNode* l1 = head, *l2 = rev;
        while (l2) {
            ListNode* tmp1 = l1->next, *tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};