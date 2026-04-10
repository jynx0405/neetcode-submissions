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
        ListNode*cur=head;
        if (head==NULL && n>0) return NULL;
        int size=0;
        while(cur!=NULL){
            cur=cur->next;
            size++;
        }
        if(n == size){
            return head->next;
        }
        int N=size-n-1;
        cur=head;
        int count=0;
        while(count<=N-1){
            cur=cur->next;
            count++;
        }
        cur->next=cur->next->next;

        
        return head;
    }
};
