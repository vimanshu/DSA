// create a program to convert infix to postfix
#include <iostream>
#include <stack> // use of stack stl
using namespace std;
void infix_to_postfix(string &s){
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if(s[i]>=97 && s[i]<=122){
      cout<<s[i];
    }
    else{
          
    if(s[i]=='^'){
      st.push(s[i]);
    }
    
    else if(!st.empty() && st.top()!='+') && (!st.empty() && st.top()!='-')){
      
        while(!st.empty() && st.top()!='+') {
          //ask bhaiya
          //(!st.empty() && st.top()!='+') ||(!st.empty() && st.top()!='-')
          //pop condition
          cout<<st.top();
          st.pop();
          
        }
        // nahi to push
      st.push(s[i]);
      
      
    }
    else {
      // condition whe n s[i]== + or -
      while(!st.empty()){
        cout<<st.top();
        st.pop();
      }
      st.push(s[i]);
      
    }
    }
  }


while(!st.empty()){
    cout<<st.top();
    st.pop();
  }
} 

int main(){
  string s="a*b*c+d*e";
  infix_to_postfix(s);
  return 0;
}
