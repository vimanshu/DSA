// wap for bi-partite graph -- graph colouring problem


#include <iostream>
#include <vector>
using namespace std;
bool bipartite(vector<vector<int>> &graph, int curr, vector<int> &visited, vector<int> &color, int curr_color){
  visited[curr]=true;
  color[curr]=curr_color;
  for(int child: graph[curr]){
    if(visited[child]==false){
      //save the color
      if(bipartite(graph,child,visited,color,!curr_color)==false){
       return false; 
      }
    }
    else
    {
      if(color[child]==color[curr]){
        return false;
      }
    }
  }
  return true;
}
int main()
{
  int v,e;
  cin>>v>>e;
  v++;
  vector<vector<int>> graph(v,vector<int>(0));
  // establishing the edges
  for (int i = 0; i < e; i++) {
    int s,d;
    cin>>s>>d;
    graph[s].push_back(d);
    graph[d].push_back(s);
  }
  vector<int> visited(v,false);
  vector<int> color(v,-1);
  cout<<bipartite(graph,1,visited,color,0);
    return 0;
}
