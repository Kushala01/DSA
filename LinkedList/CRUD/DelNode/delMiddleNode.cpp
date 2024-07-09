Node* deleteMiddle(Node* head){
    if(head==NULL|| head->next==NULL)
        return NULL;
    Node* slow = head,*fast = head,*prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete(slow);
    return head;
}