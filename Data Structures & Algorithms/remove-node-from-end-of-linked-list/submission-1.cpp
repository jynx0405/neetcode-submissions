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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *r=head;
        int count =0;
        while(r && count<n){
            r=r->next;
            count++;
        }
        ListNode buf;
        buf.val=0;
        buf.next=head;
        ListNode* l=&buf;
        while(r){
            r=r->next;
            l=l->next;
        }
        l->next=l->next->next;
        return buf.next;


    }
};
