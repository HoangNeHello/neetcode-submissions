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
        // Counting the length
        int L=0;
        ListNode* counting = head;
        while (counting != nullptr) {
            L++;
            counting = counting->next;
        }

        // Use the dummy to retrieve the list
        ListNode dummy;
        dummy.next = head;
        ListNode* curr = &dummy;
        int count = L-n;
        while (curr != nullptr && count >= 0) {
            if (count == 0) {
                curr->next = curr->next->next; // Skip it
            }

            count--;
            curr = curr -> next;
            
        }

        return dummy.next;
    }
};
 