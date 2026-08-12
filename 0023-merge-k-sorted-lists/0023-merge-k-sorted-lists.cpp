class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> arr;

        // 1. Saare linked lists traverse karo
        for (ListNode* head : lists) {
            while (head != nullptr) {
                arr.push_back(head->val);
                head = head->next;
            }
        }

        // 2. Saare values sort karo
        sort(arr.begin(), arr.end());

        // 3. Sorted values se linked list banao
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int x : arr) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy->next;
    }
};