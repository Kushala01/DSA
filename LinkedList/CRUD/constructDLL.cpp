class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        int size=arr.size();
        if(size==0) return NULL;
        Node* head=new Node(arr[0]);
        Node* current=head;
        
        for(int i=1;i<size;i++){
            Node* newNode= new Node(arr[i]);
            newNode->prev=current;
            current->next=newNode;
            current=current->next;
        }
        return head;
    }
};