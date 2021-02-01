// write a code for the minimum spanning tree 
// the meaning of minimum spanning tree 
// minimum cost spanning tree


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct edge{
    int s,d,wt;
};
bool comparator(edge a, edge b){
    if(a.wt<b.wt){
        return 1;
    }
    else
    return 0;
}
int find(int s, vector<int> &parent){
    // for finding the super parent till it  gets -1, 
    // any node that has -1 as element is a node
    if(parent[s]==-1){
        return s;
    }
    else
    return parent[s]=find(parent[s],parent); // update the parent find the parent of the element
                                    // this is also path compression
    
}
void union_(int p1, int p2, vector<int> &parent, vector<int> &rank){
    // union hone ke liye kya condition tha
    if(p1!=p2){
        // check the rank for the updation of rank
        if(rank[p1]>rank[p2]){
            parent[p2]= p1; // parent of p2 is p1
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2; // parent of p1 is p2
        }
        else{
            parent[p2]=p1;
            rank[p1]+=1;
        }
    }
}
int kruskal(vector<edge>&edges, int v, vector<int> &parent,
    vector<int> &rank ){
    // first sort the edges vector on the basis of wt
    sort(edges.begin(), edges.end(), comparator);
    // start adding the edges or creating the union
    vector<edge> mst;
    int i=0; // iterating the edges
    int c=0; // condition for checking the number of edge for the spanning tree
    while(c<v-1 && i<edges.size()){
        // check the condition for cycle when parent of e1 == parent of e2
        int p1= find(edges[i].s,parent);
        int p2= find(edges[i].d,parent);
        if(p1!=p2){
            union_(p1,p2,parent,rank);
            mst.push_back(edges[i]); // pushing the selected mst edge
            c++;
           
        }
       i++; 
    }
    int sum=0;
    for (int i = 0; i < mst.size(); i++) {
        sum+=mst[i].wt;
    }
    return sum;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> parent(v,-1);
    vector<int> rank(v,0);
    vector<edge> edges; // a vector of type edge
    for (int i = 0; i < e; i++) {
        int s,d,wt;
        edge temp; // creating an object of struct edge
        cin>>temp.s>>temp.d>>temp.wt;
        edges.push_back(temp);
        
        
    }
    // print what we have in vector edges
//   for (int i = 0; i < edges.size(); i++) {
//      cout<<edges[i].s<<" "<<edges[i].d<<" "<<edges[i].wt<<" ";
//   }
    cout<<kruskal(edges,v,parent,rank);
  
}
