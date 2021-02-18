// fifo implementation using array
#include <iostream>

using namespace std;
void display(int front, int rear, int *q){
  for (int i = front; i <= rear; i++) {
    cout<<q[i]<<" ";
  }
  cout<<endl;
}
void enqueue(int *q,int &front, int &rear, int x){
  // condition for overflow
  if(rear==9999){
    cout<<"overflow";
    exit(0);
  }
  else{
    if(rear==-1 || front==-1){
        front++;
    }
    rear++; 
    q[rear]=x;
  }
  display(front,rear,q);
}
void dequeue(int &front, int &rear, int *q){
  // condition for underflow
  if(front==-1){
    cout<<"underflow";
    exit(0);
  }
  else if(front==rear){
    cout<<"memory free";
    front=-1;
    rear=-1;
    cout<<"ready to fill from the begining"<<"since front="<<front<<endl;
  }
  else{
    front++;
    display(front,rear,q);
  }
}
int main()
{
    int q[10000];
    int front=-1;
    int rear=-1;
    int t;
    cin>>t;
    while(t--)
    {
      char ch;
      cin>>ch;
      
      if(ch=='e'){
        int x;
        cin>>x;
    enqueue(q,front,rear,x);
      }
      else
      dequeue(front,rear,q);
    }
    return 0;
}
