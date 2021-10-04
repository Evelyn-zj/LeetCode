/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *current;
        current = headA;
        int n, m;
        n = 0;
        m = 0;
        while (current != nullptr) {
            n++;
            current = current->next;
        }
        current = headB;
        while (current != nullptr) {
            m++;
            current = current->next;
        }
        ListNode *ctrA, *ctrB;
        ctrA = headA;
        ctrB = headB;
        if (n < m) {
            ctrA = headB;
            ctrB = headA;
        }
        for (int i = 0; i < abs(n-m); ++i) {
            ctrA = ctrA->next;
        }
        while (ctrA != ctrB) {
            ctrA = ctrA->next;
            ctrB = ctrB->next;
        }
        return ctrA;
    } 
};