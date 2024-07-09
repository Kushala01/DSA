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

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    int res = cnt - N;
    temp = head;

    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}
//Time Complexity: O(L)+O(L-N)
//Space Complexity:  O(1)