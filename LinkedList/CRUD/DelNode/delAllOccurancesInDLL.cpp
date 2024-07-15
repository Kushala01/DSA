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
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if (*head_ref == NULL)
            return;

        Node *current = *head_ref;
        Node *prev = NULL;

        while (current != NULL) {
            if (current->data == x) {
                if (current == *head_ref) {
                    *head_ref = current->next;
                    if (*head_ref != NULL)
                        (*head_ref)->prev = NULL;
                } else {
                    prev->next = current->next;
                    if (current->next != NULL)
                        current->next->prev = prev;
                }
                Node *toDelete = current;
                current = current->next;
                delete toDelete;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
};