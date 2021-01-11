

#include <iostream>

using namespace std;
//-----------------------------------------------------------------
struct node{
  int val;
  struct node*next; // [val|next]
};
//-----------------------------------------------------------------
struct node *createNode(int v){
  //creating a node means giving space
  struct node*p=(struct node*)malloc(sizeof(struct node));
  p->val=v;
  p->next=NULL;
  
  return p;  
}
//-----------------------------------------------------------------
void print(node*head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head=head->next;
  }
}
//-----------------------------------------------------------------

void insert_last(struct node*head, int x){
  while(head->next!=NULL){
    head=head->next;
  }
  struct node*p=createNode(x);
  head->next=p; // adding up the link
}
// ----------------------------------------------------------------
void search(node*head, int x){
  int flag=0;
  while(head!=NULL){
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
int main()
{
    struct node*head=NULL; // head->null
    struct node *p=createNode(1); //creating a node
    head=p;
    p= createNode(2);
    head->next=p;
    insert_last(head,3);
    insert_last(head,4);
    insert_last(head,5);
    // to find whether an element exists in linked list or not.
    search(head,5);
    search(head,6);
    
   // print(head);
 
    return 0;
}
