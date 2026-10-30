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
    bool hasCycle(ListNode* head) {
        ListNode* q1 = head;
        ListNode* q2 = head;

        while (q1 != nullptr && q2 != nullptr && q2->next != nullptr) {
            q1 = q1->next;
            q2 = q2->next->next;
            if (q1 == q2) return true;
        }

        return false;
    }
};
