struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node *head){
        // Edge case: empty list or single node
        if (head == NULL || head->next == NULL)  return head;
        
        Node *current = head;
        while (current->next != NULL) {
            if (current->data == current->next->data) {
                Node *nextNode = current->next;
                current->next = nextNode->next;
                if (nextNode->next != NULL)
                    nextNode->next->prev = current;
                delete nextNode;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
//Time Complexity: O(n)
//Space Complexity: O(1)