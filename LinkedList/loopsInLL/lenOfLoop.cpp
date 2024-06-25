#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head) {
    Node *slow = head, *fast = head;

    // Phase 1: Detect the loop using Floyd's Cycle-Finding Algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there's a loop
        if (slow == fast) {
            // Phase 2: Count the number of nodes in the loop
            int loop_length = 1;
            Node *current = slow;

            // Move in the loop until we reach the same node again
            while (current->next != slow) {
                current = current->next;
                loop_length++;
            }
            return loop_length;
        }
    }

    // No loop found
    return 0;
}

int main() {
    // Create a sample linked list with a loop
    Node* node1 = new Node(25);
    Node* node2 = new Node(14);
    node1->next = node2;
    Node* node3 = new Node(19);
    node2->next = node3;
    Node* node4 = new Node(33);
    node3->next = node4;
    Node* node5 = new Node(10);
    node4->next = node5;
    Node* node6 = new Node(21);
    node5->next = node6;
    Node* node7 = new Node(39);
    node6->next = node7;
    Node* node8 = new Node(90);
    node7->next = node8;
    Node* node9 = new Node(58);
    node8->next = node9;
    Node* node10 = new Node(45);
    node9->next = node10;

    // Make a loop from node10 to node4 (4th node from beginning, 1-based index)
    node10->next = node4;

    Node* head = node1;

    // Find the length of the loop in the linked list
    int loop_length = countNodesinLoop(head);

    if (loop_length > 0) {
        cout << "Loop detected. Length of the loop is: " << loop_length << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}

//This solution has an expected time complexity of 𝑂(𝑁) and uses 𝑂(1) auxiliary space

/*Phase 1: Detecting the Loop:
The slow and fast pointers traverse the list to detect a loop. In the worst case, 
both pointers will traverse the entire list, resulting in a time complexity of O(N).
Phase 2: Counting Nodes in the Loop:
Once a loop is detected, we use the current pointer to count the number of nodes in the loop. 
In the worst case, this involves traversing the loop, which can also be up to 
O(N) in the worst case if the loop includes all nodes.
Since both phases are sequential and each phase individually takes 
O(N), the overall time complexity remains O(N).*/