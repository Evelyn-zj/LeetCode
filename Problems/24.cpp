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
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur;
        cur = head;
        while (cur != nullptr) {
            if (cur->next != nullptr) {
                int temp;
                temp = cur->val;
                cur->val = cur->next->val;
                cur->next->val = temp;
                cur = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};