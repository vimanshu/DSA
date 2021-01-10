// A program to explain how to create a linked list
#include <iostream>

using namespace std;
struct node{
  int val;
  struct node *next;
};
struct node *createNode(int v){
  // now here creting a node means giving space 
  // which can be creted using malloc
  struct node*p=(struct node*)malloc(sizeof(struct node));
  p->val=v;
  p->next=NULL;
  return p; // return type is pointer
};

void print(struct node*n){
  while(n!=NULL){
    cout<<n->val<<" ";
    n=n->next;
  }
  
}

int main()
{
    //first create head
    struct node *head=NULL;
    struct node *p=createNode(1);
    head=p; // head now direct to the first memory location where the first elememt is stored
    p= createNode(2);     //p now holds the value of  memory location where 2 is stored
    head->next=p; // now next of first node stores the mem ad where 2 is stored
    
    p=createNode(3);
    head->next->next=p; // 2nd node's next now stores the mem add of 3rd node where 3 is present
    
    print(head);
    return 0;
}
