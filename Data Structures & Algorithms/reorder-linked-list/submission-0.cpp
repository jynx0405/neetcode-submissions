class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL;

        while (curr) {
            ListNode* next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        int count = 0;
        ListNode* c = head;
        while (c) {
            count++;
            c = c->next;
        }

        int half = (count + 1) / 2;

        c = head;
        for (int i = 1; i < half; i++) {
            c = c->next;
        }

        ListNode* second = c->next;
        c->next = NULL;

        ListNode* q = reverseList(second);

        ListNode* p = head;

        while (p && q) {
            ListNode* p1 = p->next;
            ListNode* q1 = q->next;

            p->next = q;
            q->next = p1;

            p = p1;
            q = q1;
        }
    }
};