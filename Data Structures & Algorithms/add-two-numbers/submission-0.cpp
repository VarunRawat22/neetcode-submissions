
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        // Continue if nodes or carry remain
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Create node with unit digit
            temp->next = new ListNode(sum % 10);

            // Calculate carry
            carry = sum / 10;

            // Move result pointer
            temp = temp->next;
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
