#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;       
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* detectLoop(Node* head) {
    Node* temp = head;
    unordered_map<Node*, int> mp;
    
    while(temp != NULL) {
        if(mp.count(temp) != 0) {
            return temp;
        }
        mp[temp] = 1;
        temp = temp->next;
    }

    return nullptr; 
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* node3 = new Node(3);
    node2->next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4->next = node5;
    node5->next = node2;

    Node* head = node1;

    Node* loopStartNode = detectLoop(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}
/*Time Complexity: O(N) The code traverses the entire linked list once, where 'N' is the number
 of nodes in the list. Therefore, the time complexity is linear, O(N).

Space Complexity : O(N) The code uses a hash map/dictionary to store encountered nodes,
 which can take up to O(N) additional space, where 'n' is the number of nodes in the list.
  Hence, the space complexity is O(N) due to the use of the map to track nodes.*/