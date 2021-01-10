#include <bits/stdc++.h>

using namespace std;
bool isValid(vector<string> &a,int row,int col){
  // in this we check the validity of queen being placed,satisfies or not
  
  for (int i = row; i >=0; i--) {
    // this is done to check if it exists in a row or not
    if(a[i][col]=='*'){
      return 0;
    }
  }
  //for checking the acute diagonal
  int i=row-1;
  int j=col+1;
  while(i>=0 && j<=a.size()-1){
    if(a[i][j]=='*'){
      return 0;
    }
    i--;
    j++;
  }
  
   // checking for obtuse diagonal
  // -
  //   -
  //     -
  //       -
  i=row-1;
  j=col-1;
  while(i>=0 && j>=0){
    if(a[i][j]=='*'){
      return 0;
    }
    i--;
    j--;
  }
  return 1;
}

void print(vector<string> &a){
  int n=a.size();
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}
void nQueen(vector<string> &a, int row){
  // base condition
  if(row==a.size()){
    print(a);
  }
  for (int col = 0; col < a.size(); col++) {
    // condition for placing a QUEEN 
    // intitially being in 1st row and moving along the column
    if(isValid(a,row,col)){
      a[row][col]='*'; // placing queen if true
      nQueen(a,row+1); // calling func to place the next queen in the next row
      a[row][col]='.'; // if calling func doesn't put any queen.
    }
  }
}
int main()
{
  cout<<"type n for the n queen problem";
  
  int n;
  cin>>n;
  string s;
  for(int i=0; i<n;i++){
    s.push_back('.');
  }
  // making a n*n matrix
  vector<string> a;
  for (int i = 0; i < n; i++) {
    a.push_back(s);
  }
  
  // printing the initial situation
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  
  //now we need to place queens such that no queen contradicts other
  cout<<endl;
  nQueen(a,0);
  
  return 0;
  }
