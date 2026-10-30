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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) { // Each iteration pass ONE group
            // Find k-th node of the group
            ListNode* kth = groupPrev;
            for (int i=0; i<k && kth!=nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) break; // < k then leave as is 

            ListNode* groupNext = kth->next; // first node of the next group, saved so we don't lose the rest

            // Reverse until groupNext
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next; // Start reversing at the group first node
            while (curr != groupNext) { // stop when curr reaches the next group
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Plug the group back in 
            ListNode* oldFirst = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldFirst;
        }

        return dummy.next;
    }
};
