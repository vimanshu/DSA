#include <bits/stdc++.h>

using namespace std;
void permu(string &a,int curr){
  //base condition
  if(curr==a.size()){
    cout<<a<<endl;
    
  }
  else{
    //store the value into another temp
    for (int i = curr; i < a.size(); i++) {
          string s1=a;
      swap(s1[i],s1[curr]);
    permu(s1,curr+1);
    }

  }
}
int main()
{
    string a="ABC";
    // wap to print all the combination of the string
    // i.e. 
    
    permu(a,0); // this is string ,curr, empty vector

    return 0;
}
