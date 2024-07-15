#include <iostream>
#include <vector>

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* segregate(Node *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int count[3] = {0, 0, 0}; // To store the count of 0s, 1s, and 2s

        Node* current = head;
        while (current != nullptr) {
            count[current->data]++;
            current = current->next;
        }

        current = head;
        int index = 0;
        while (current != nullptr) {
            if (count[index] == 0) {
                index++;
            } else {
                current->data = index;
                count[index]--;
                current = current->next;
            }
        }
        return head;
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " "; 
        temp = temp->next; 
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
Node* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int N = 8;
    std::vector<int> values = {1, 2, 2, 1, 2, 0, 2, 2};
    Node* head = createLinkedList(values);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    Solution sol;
    head = sol.segregate(head);

    std::cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
//Time Complexity:O(N)+O(N)=O(N)
//Space Complexity:O(1)