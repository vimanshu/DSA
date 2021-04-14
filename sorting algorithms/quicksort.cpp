// quicksort algorithm

#include <bits/stdc++.h>

using namespace std;
int partition(vector<int> &ar1, int low, int high){
    int pivot=ar1[high-1];
    int i=low-1;
    for (int j = low; j < high-1; j++) {
        if(ar1[j]<pivot){
            i++; // left ki taraf rahega
            swap(ar1[i],ar1[j]);
        }
    }
    swap(ar1[i+1],ar1[high-1]);
    return i+1;
}
void quicksort(vector<int> &ar1, int low, int high){
    if(low<high){
        int pi= partition(ar1,low,high);
        quicksort(ar1,low,pi-1);
        quicksort(ar1,pi+1,high);
    }
}
int main()
{
    //vector<int> ar1={1,3,5,7};
    vector<int> ar1={0,7,5,9,1};
    // remember where are you using the pivot
    quicksort(ar1,0,5);
    for (int i = 0; i < ar1.size(); i++) {
        cout<<ar1[i]<<" ";
    }
    
}
