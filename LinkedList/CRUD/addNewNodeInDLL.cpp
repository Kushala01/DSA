#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};
void addNode(Node *head, int pos, int data)
{
   Node* temp=head;
   int idx=0;
   while(temp->next!=NULL){
       if(idx==pos){
           Node* newNode=new Node(data);
           temp->next->prev=newNode;
           newNode->next=temp->next;
           newNode->prev=temp;
           temp->next=newNode;
       }temp=temp->next;
       idx++;
   }if(idx==pos){
           Node* newNode=new Node(data);
           temp->next=newNode;
           newNode->next=NULL;
           newNode->prev=temp;
       }
}