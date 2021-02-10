#include <iostream>
#include <stack>
using namespace std;
void postfixToInfix(string s){
  stack<string> st;
  for (int i = 0; i < s.size(); i++) {
    if(s[i]>=92 && s[i]<=122){
      //for the operands
      string temp="";
      temp=s[i];
      st.push(temp);
    }
    else{
      //for the operators
      string y= st.top();
      st.pop();
      string x=st.top();
      st.pop();
      string temp="(";
      temp+=x;
      temp+=s[i];
      temp+=y;
      temp+=")";
      st.push(temp);
    }
  }
  // so now the satck will have the proper infix solution
  cout<<st.top();
}
int main()
{
string s="ab*c+";
postfixToInfix(s);
}
