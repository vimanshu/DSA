// wap to find for cycle in a graph--
// This question can have two types 
// finding in directed graph--
// finding in undirected graph--
// i am going to use dfs to find in undirected graph
// the only concept to use-> the backedge detection

#include <iostream>
#include <vector>
using namespace std;
bool cycleDetect(vector<vector<int>> &graph, int curr, vector<int>&visisted, 
                  int parent){
                  visisted[curr]=true;
                  for(int child: graph[curr]){
                    if(visisted[child]==false){
                      if(cycleDetect(graph,child,visisted,curr)==true){
                        return true;
                      }
                    }
                    else{
                      //if visited
                      if(parent!=child){
                        return true;
                      }
                    }
                  }
      
                return false;  
                  }
int main(){
  int v,e;
  cin>>v>>e;
  v++;
  vector<vector<int>> graph(v,vector<int>(0,0));
  for (int i = 0; i < e; i++) {
    int s,d;
    cin>>s>>d;
    graph[s].push_back(d);
    graph[d].push_back(s);
  }
  
  vector<int> visited(v,false);
  cout<<cycleDetect(graph,1,visited,-1);
  
}
/* input:
5 4
1 2
1 5
2 3
2 4
3 4
*/
