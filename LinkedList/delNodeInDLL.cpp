struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
         if (head == NULL) return head;

        Node* temp = head;

        if (x == 1) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }

        for (int i = 1; temp != NULL && i < x; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return head;

        if (temp->next == NULL) {
            temp->prev->next = NULL;
            delete temp;
            return head;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

        return head;
    }
};