
// paranthesis completion code using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool paraBalance(string s){
  stack<char> stac;
  for (int i = 0; i < s.size(); i++) {
    if(s[i]=='('){
      stac.push(s[i]);
    }
    else
    stac.pop();
  }
  if(!stac.empty()){
    cout<<"not balanced";
    return false;
  }
  else
  cout<<"balanced";
  return true;
}

int main()
{
    string s="(((())";
    paraBalance(s);

    return 0;
}

