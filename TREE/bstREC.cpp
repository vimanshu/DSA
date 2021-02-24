#include <iostream>

using namespace std;
struct node{
  node *left;
  int data;
  node *right;
};
node *create_node(int x){
  // allocating memory in the heap area
  node *p= (node *)malloc(sizeof(node));
  p->left=NULL;
  p->data=x;
  p->right=NULL;
  return p;
}
node *insert_bst(node *root, int x){
  if(root==NULL){
    root=create_node(x);
  }
  else
  {
    if(root->data>x){
      // x should go as left child
      root->left= insert_bst(root->left,x);
    }
    else
    root->right=insert_bst(root->right,x);
  }
}
void inorder(node *root){
  // inorder moves as [left-> rootData-> right]
  if(root==NULL){
    return;
  }
  else
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
int main()
{
    node *root=NULL;
    int t;
    cin>>t;
    while(t--){
      int x;
      cin>>x;
      root=insert_bst(root,x);
      
    }
    inorder(root);
    return 0;
}

// remember: Inorder+BST= ascending/increasing order
/*
input:
5                                                                                                                        
3 7 8 9 6 
*/
