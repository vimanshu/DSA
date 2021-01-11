// hashing 
// key value pair
// ex country--> capital
//    cuba --> havana
//    england--> London
//    france -->paris
// you have given an array which contains both positive and non-positive numbers,
// elements are in the range from -max to +max
// and we need to find in O(1)
// how to handle negative numbers?
// sol- get a 2-d array 0->|0 0 0 0 0 0 0 |
//                      1->|0 0 0 0 0 0 0 |
// 
#include <iostream>
#define MAX 1000
using namespace std;

bool hasht[MAX+1][2];
// this code below is used for searching
bool search(int x){
  if(x>=0){
    if(hasht[x][0]==1){
      return true;
    }
    else
    return false;
    
  }
  else{
    x= abs(x);
    if(hasht[x][1]==1){
      return true;
    }
    else{
    return false;
    }
  }
}
void insert(int a[], int n){
  for (int i = 0; i < n; i++) {
    if(a[i]>=0){
      hasht[a[i]][0]=true;
    }
    else{
      hasht[abs(a[i])][1]=true;
    }
  }
}
int main()
{
   int arr[]={-1,9,2,-5,3,1}; //we need to store this into hash table 
    int n= sizeof(arr)/sizeof(arr[0]);
    insert(arr,n);
    int find = -1;
    cout<<search(find);
}
