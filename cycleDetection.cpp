//write a program for cycle detection using DFS
// here we'll use a concept of backedge--> a child connected to ancestor
// know who is a parent and who is an ancestor
// backedge for cycle detection for undirected as well as directed
#include <iostream>
#include <vector>
using namespace std;
bool cycleDetection(vector<vector<int>>&graph, int curr, vector<int> &visited, int parent){
  visited[curr] = true;
  for(int child: graph[curr]){
    if(visited[child]==false){
      if(cycleDetection(graph,child,visited,curr)==true){
        return true;
      }
    }
    else{
      if(child!=parent){
        //backedge 
        return true;
      }
    }
  }
  return false;
}
int main()
{
  int v,e;
  cin>>v>>e;
  v++;
  vector<vector<int>> graph(v,vector<int>(0));
  for (int i = 0; i < e; i++) {
    int s,d;
    cin>>s>>d;
    graph[s].push_back(d);
    graph[d].push_back(s);
  }
  vector<int> visited(v,false);
  // last parameter is parent
  cout<<cycleDetection(graph,1,visited,-1);
  

    return 0;
}

// to do--> find how many cycles are there in the graph
