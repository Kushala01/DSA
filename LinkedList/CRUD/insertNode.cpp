#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void PrintList(ListNode *head) {
    ListNode *curr = head;
    for (; curr != NULL; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

ListNode *InsertatFirst(int value, ListNode *head) {
    ListNode *newnode = new ListNode(value);
    newnode->next = head;
    head = newnode;
    return head;
}

int main() {
    ListNode *head = NULL;
    head = InsertatFirst(40, head);
    head = InsertatFirst(30, head);
    head = InsertatFirst(20, head);
    head = InsertatFirst(10, head);
    cout << "LinkedList before inserting 0 at beginning: " << endl;
    PrintList(head);
    head = InsertatFirst(0, head);
    cout << "LinkedList after inserting 0 at beginning: " << endl;
    PrintList(head);
    return 0;
}