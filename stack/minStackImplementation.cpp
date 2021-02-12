// make a min stack
#include <iostream>
#include <stack>
#include <climits>
using namespace std;
void push_culture(stack<int> &stac, int y, int &curr_min, stack<int> &stacForMin){
  if(curr_min>y){
    curr_min=y;
  }
  stac.push(y);
  cout<<"stack- "<<stac.top()<<endl;
  stacForMin.push(curr_min);
  cout<<"stackForMin- "<<stacForMin.top()<<endl;
}
void pop_culture(stack<int> &stac,int &curr_min, stack<int> &stacForMin ){
  
  while(!stacForMin.empty() &&stacForMin.top()==curr_min){
    stacForMin.pop();
    
  }
  if(!stacForMin.empty()){
  curr_min=stacForMin.top();
  cout<<"the min in stack now- "<<stacForMin.top()<<endl;
    
  }
  else
  cout<<"the min now is nothing"<<endl;
}
void min_find(stack<int> &stacForMin){
  cout<<stacForMin.top()<<endl;
}
int main(){
  // taking the input
  
  int t;
  cin>>t;
  stack<int> stac;
  stack<int> stacForMin;
  int curr_min=INT_MAX;
  cout<<"what you want to do"<<endl;
    cout<<"press 1 for push\n press 2 for pop\n press 3 to get min from the stack"<<endl;
  for (int i = 0; i < t; i++) {
    int x;
    cin>>x;
    switch(x){
      case 1:
        int y;
        cin>>y;
        push_culture(stac,y,curr_min,stacForMin);
        break;
      case 2:
        pop_culture(stac,curr_min,stacForMin);
        break;
      case 3:
      min_find(stacForMin);
      break;
    }
  }
}

/* input:
10
1 1
1 2
1 3
1 4
1 0
1 5
1 -1
2
2
2
*/
