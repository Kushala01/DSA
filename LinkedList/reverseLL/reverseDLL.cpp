{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node* prev=NULL;
        Node* current=head;
        
        while(current!=NULL){
            prev=current->prev;
            current->prev=current->next;
            current->next=prev;
            
            current=current->prev;
        }
        
        return prev->prev;
    }
};