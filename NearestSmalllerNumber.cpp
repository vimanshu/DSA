// wap to find the nearest smallest number in a given array

#include <bits/stdc++.h>
using namespace std;
void solution(int *ar, int n){
  // calling the array bu the reference using the pointer
  // make the stack cause its a stack question and we like it
  stack<int> stac;
  vector<int> sol;
  
 
  for(int i=0; i<n; i++){
    // think about the push/pop condition
    while(!stac.empty() && stac.top()>=ar[i]){
      stac.pop();
    }
    if(stac.empty()){
      sol.push_back(-1);
      stac.push(ar[i]);
    }
    else{
    sol.push_back(stac.top());
    stac.push(ar[i]);
      
    }
  }
  for (int i = 0; i <sol.size() ; i++) {
    cout<<sol[i]<<" ";
  }
}
int main(){
  int ar[]={1,2,3,4,5,0,7};
  int n=sizeof(ar)/sizeof(ar[0]);
  solution(ar,n);
}
