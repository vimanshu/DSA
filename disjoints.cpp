// working on the disjoint set

#include <iostream>
#include <vector>
using namespace std;
int find(int a,vector<int> &parent){ // based on the recursion
    if(parent[a]==-1){
        return a;
    }
    else{
        return parent[a]=find(parent[a],parent); //path compression
    }
}

void union_(int a, int b,vector<int> &parent, vector<int> &rank){
    int p1= find(a,parent); // finding super parent of a
    int p2= find(b,parent); // finding super parent of b
    if(p1!=p2){
        //check rank then update parent
        if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else{
            parent[p2]=p1;
            rank[p1]+=1;
        }
    }
    // if p1 and p2 is equal then it's a condition for cycle
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> parent(v,-1);
    vector<int> rank(v,0);
    
    for (int i = 0; i < e; i++) {
        int s,d;
        cin>>s>>d;
        union_(s,d,parent,rank);
    }

    // wap for finding the number of connected components
    int c=0;
    for(int x: parent){
        if(x==-1){
            c++;
        }
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<c;
    return 0;
}
