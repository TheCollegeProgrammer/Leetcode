class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Check karo ki k nodes available hain ya nahi
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            // Next group ka starting node
            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* next = curr->next;

                curr->next = prev;

                prev = curr;
                curr = next;
            }

            // Previous group ko reversed group se connect karo
            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;

            groupPrev = temp;
        }
    }
};