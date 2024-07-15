class Solution{
     Node* reverse(Node *head){
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = head->next;
        
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
     }
    public:
    Node* addOne(Node *head) {
        // return head of list after adding one
            if(head==NULL) return NULL;
        
        head = reverse(head);
        Node *curr = head;
        
        while(curr!=NULL){
              //when only one node is present in linkedlist
            if(curr->next == NULL && curr->data == 9){
                curr->data = 0;
                Node *newdata = new Node(1);
                curr->next = newdata;
                curr = curr->next;
                break;
            }
          //if the node data is 9
            else if(curr->data == 9){
                curr->data = 0;
                curr = curr->next;
            }
            else{
                curr->data = curr->data + 1;
                curr = curr->next;
                break;
            }
        }
        return reverse(head);
    }
};
//time complexity: o(n)
//space complexity: o(1)