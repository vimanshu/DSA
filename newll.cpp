

#include <iostream>

using namespace std;

struct node{
  int val;
  struct node*next; // this is self referential structure
};
struct node *createNode(int v){
  // create memory in the heap area using malloc
  struct node *p=(struct node *)malloc(sizeof(struct node));
  p->val=v;
  p->next=NULL;
} 
void print(struct node *head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head=head->next;
    
  }
}
void insertAtEnd(struct node *head, int x){
  while(head->next!=NULL){
    head=head->next;
  }
  // create a node
  struct node*p=createNode(x);
  head->next=p; //linked
}
void search(struct node *head, int x){
  int flag=0;
  while(head->next!=NULL){
    // i'll search for the val
    if(head->val==x){
      flag=1;
      break;
    }
    head=head->next;
  }
  if(flag==1){
    cout<<"found"<<endl;
  }
  else
  cout<<"not found"<<endl;
}
bool isEmpty(struct node*head){
  if(head==NULL){
    return true;
  }
  else 
  return false;
}
int sizeofLL(struct node *head){
  int count=0;
  while(head!=NULL){
    count++;
    head=head->next;
  }
  return count;
}
struct node *insertAtBeg(struct node*head, int x){
  struct node *temp=head;
  //crete the node required with the value
  struct node *p=createNode(x);
  head=p;
  head->next=temp;
  return head;
}
struct node *deleteAtBeg(struct node *head){
  head= head->next; // linked with the 2nd element
  return head;
}
struct node *delete_at_i(struct node*head,int i, int n){
 
 // cout<<i<<endl;
  if(i>n){
    cout<<"out of bound to delete"<<endl;
    return head;
  }
  if(i==1){ //for the first element to be deleted
    head=head->next;
    return head;
  }
  if(i==n){ // for the last element to to deleted
  //cout<<"i'm here"<<endl;
    int t=0;
    struct node *fhead=head;
    while(t<i){
      fhead=fhead->next;
      t++;// traversal to the 2nd last index
    }
    fhead->next=NULL; // pointing towards null
    return head;
  }
  
else{
   struct node *fhead=head; // crete a copy of the head
  int t=0;
  
  while(t<i){
    fhead=fhead->next;
    t++;
  }
  struct node*temp1=fhead;
  struct node *temp2= fhead->next->next;
  temp1->next=temp2;
  return head;
}
}
int main()
{
    struct node *head=NULL;
    struct node *p=createNode(1);// instance of struct type node
    head=p; // head will now point to p;
    // to insert a node at the end
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);

    
    print(head); // need a print function to print the nodes created
    cout<<endl;
    
    // now let's create something to search if a given value is present in the
    // not
    
    search(head,4);
    
    // lets make a function that returns true or false if size is empty or not
    cout<<isEmpty(head);
    cout<<endl;
    
    // let's make a function which returns the size or the number of nodes in the
    // linked list
    cout<<sizeofLL(head);
    
    // let's create a function which inserts the node at the front/beginning
    head=insertAtBeg(head,0);
    cout<<endl;
    print(head);
    // write a function to delete first 
    head=deleteAtBeg(head); // meaning delink the linked list
    cout<<endl;
    
    cout<<"delete At beginning"<<endl;
    print(head);
    
    // write a function to delete the ith node in the linkedlist
    int n=sizeofLL(head);
    cout<<"enter what element to delete starting from 1"<<endl;
    int i;
    cin>>i;
    head=delete_at_i(head,i,n); // passing the head and the size of linkedlist
    print(head);
    
    return 0;
}
