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
    ListNode* reverseList(ListNode* head) {
        return (reverse_help(head,NULL));
    }
    ListNode* reverse_help(ListNode* cur,ListNode* prev){
        if(cur==NULL) return prev;
        ListNode* nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
        return reverse_help(cur,prev);
    }
};
