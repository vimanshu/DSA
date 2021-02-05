#include <iostream>
using namespace std;
struct node{
  int val;
  struct node *next; // self referential structure
};
struct node * createNode(int x, node *top){
  //mallocate the memory
  struct node *p=(struct node *)malloc(sizeof(struct node));
  p->val=x;
  p->next=NULL; //check for error
  return p;
}
struct node * push(int x, node *top){
  struct node *p=createNode(x, top);
  // condition for overflow
  // when heap memory is full or it returns NULL
  if(p==NULL){
    cout<<"overflow";
    exit(0);
  }
  else{
  p->next=top;
  return p;
  }
}
struct node * pop(node *top){
  // condition for underflow
  if(top==NULL){
    cout<<"underflow";
    exit(0);
  }
  node *p=top;
  top=top->next;
  free(p);
  p=NULL;
  return top;
}
void display(node *p){
  while(p!=NULL){
    cout<<p->val<<" ";
    p=p->next;
  }
}
int main(){
  struct node* top=NULL;
  int op;
  cin>>op;
  while(op!=0){
    string s;
    cin>>s;
    if(s=="push"){
      int x;
      cin>>x;
      
      top=push(x,top);
      //cout<<top->val<<" ";
      node *p=top;
      display(p);
    }
    else if(s=="pop"){
      top=pop(top);
    }
    op--;
  }
  // print
  
}
