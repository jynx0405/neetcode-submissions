class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* c1=l1;
        ListNode* c2=l2;
        ListNode dummy;
        ListNode* curr=&dummy;
        dummy.next=NULL;

        while(c1 && c2){
            if(c1->val > c2->val){
                curr->next = c2;
                c2 = c2->next;
            }
            else{
                curr->next = c1;
                c1 = c1->next;
            }
            curr = curr->next;
        }

        if(c1) curr->next = c1;
        if(c2) curr->next = c2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];

        for(int i=1;i<lists.size();i++){
            ListNode* head = merge(lists[i-1],lists[i]);
            lists[i]=head;
        }
        return lists[lists.size()-1];
    }
};