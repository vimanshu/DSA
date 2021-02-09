// wap to find for cycle in a graph--
// This question can have two types 
// finding in directed graph--
// finding in undirected graph--
// i am going to use dfs to find in ****directed graph
// the only concept to use-> the backedge detection

#include <iostream>
#include <vector>
using namespace std;
bool cycleDetect(vector<vector<int>> &graph, int curr, vector<int>&visited, 
                  vector<int>&stacka){
                  visited[curr]=true;
                  stacka[curr]=true;
                  for(int child: graph[curr]){
                    //cout<<"running for- "<<child<<endl;
                    if(visited[child]==false){
                      if(cycleDetect(graph,child,visited,stacka)==true){
                        return true;
                      }
                    }
                    else{
                      //if visited
                      //cout<<"stacka[child]->"<<child<<" ";
                        if(stacka[child]==true){
                        return true;
                      }
                    }
                  }
                stacka[curr]=false;
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
    //graph[d].push_back(s);
  }
  
  vector<int> visited(v,false);
  vector<int> stacka(v,false);
  cout<<cycleDetect(graph,1,visited,stacka);
  
}

/*
input:
5 5
1 2
1 5
2 3
3 4
4 2
*/
