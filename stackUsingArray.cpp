// making the stack data structures using array implementationd

#include <iostream>

using namespace std;
void push(int x, int &top, int &arr){
  if(top==sizeof(arr)/sizeof(arr[0])-1){
    //overflow
    cout<<"overflow"<<endl;
    exit(0);
  }
  else{
    top++;
    arr[top]=x;
  }
}
void pop(int &top){
  if(top==-1){
    //underflow
    cout<<"underflow";
    exit(0);
  }
  top--;
}
int main()
{
int arr[100];
int top=-1;
cout<<"enter no of operations"<<endl;
int op;
cin>>op;
while(op!=0){
  string s;
  cin>>s;
  if(s=="push"){
    int x;
    push(x,top,arr);

  }
  else{
    pop(top);
  }
}
for (int i = top; i > -1; i--) {
  cout<<arr[i]<<" ";
}
}
