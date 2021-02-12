
// paranthesis completion code w/o stack
#include <iostream>

#include <string>
using namespace std;
bool paraBalance(string s){
  int balSum=0;
  for (int i = 0; i < s.size(); i++) {
    
    if(balSum>=0){
      if(s[i]=='('){
      balSum++;
     // cout<<"balSum-"<<balSum<<endl;
      
    }
    else
    balSum--;
    //cout<<"balSum-"<<balSum<<endl;
    }
    else{
    cout<<"not balanced";
    return false;
      
    }
  }
  
  if(balSum>0){
    cout<<"not balanced";
    return false;
  }
  else{
    cout<<"balanced";
    return true;
  }
}

int main()
{
    string s="()))))";
    paraBalance(s);

    return 0;
}
