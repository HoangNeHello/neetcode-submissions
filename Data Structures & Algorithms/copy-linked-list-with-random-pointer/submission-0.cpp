/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Use map to deep copy
        unordered_map<Node*, Node*> copyOf;
        copyOf[nullptr] = nullptr;

        // Allocate memory for all new nodes
        Node* curr = head;
        while (curr != nullptr) {
            copyOf[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Rewire and now map them. Point exactly at their location
        curr = head;
        while (curr != nullptr) {
            copyOf[curr]->next = copyOf[curr->next];
            copyOf[curr]->random = copyOf[curr->random];
            curr = curr->next;
        }

        return copyOf[head];
    }
};
