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

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // fast ko n+1 steps aage le jao
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // dono ko saath move karo
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow ke next ko delete karna hai
        ListNode* delNode = slow->next;

        slow->next = slow->next->next;

        delete delNode;

        return dummy->next;
    }
};
