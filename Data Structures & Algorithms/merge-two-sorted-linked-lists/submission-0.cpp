class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(t1 != NULL && t2 != NULL) {
            if(t1->val <= t2->val) {
                curr->next = t1;
                t1 = t1->next;
            } 
            else {
                curr->next = t2;
                t2 = t2->next;
            }

            curr = curr->next;
        }

        if(t1 != NULL) {
            curr->next = t1;
        } 
        else {
            curr->next = t2;
        }

        return dummy->next;
    }
};