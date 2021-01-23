
// ye hai graph ka code
#include <iostream>
#include <vector>

using namespace std;
//void dfs(vector<vector<int>> &graph, int curr, vector<int> &visited){
//   visited[curr]=true;
//   cout<<curr<<;
//   for(int child: graph[curr]){
//     if(visited[child]==false){
//       dfs(graph,child,visited);
//     }
//   }
// }
vector<int> singleSourceShortestPath(vector<vector<int>> &graph, int curr, vector<int> &visited, vector<int> &distance, int curr_dis){
  visited[curr]=true;
  distance[curr]=curr_dis;
  for(int child: graph[curr]){
    if(visited[child]==false){
      singleSourceShortestPath(graph,child,visited,distance,curr_dis+1);
    }
  }
  return distance;
}
int main()
{
    int v,e;
    cin>>v>>e;
    v++;
    //create a graph
    vector<vector<int>> graph(v,vector<int>(0));
    //creating the edges here
    for (int i = 0; i < e; i++) {
      int s,d;
      cin>>s>>d;
      graph[s].push_back(d);
      graph[d].push_back(s);
      
    }
    vector<int> visited(v,false);
    //dfs(graph,1,visited);
    
    // write a code for single source shortest path
    vector<int> distance(v,-1);
    //int curr_dis=0;
    vector<int> sol=singleSourceShortestPath(graph,1,visited,distance,0);
    for (int i = 0; i < sol.size(); i++) {
      cout<<i<<"->"<<sol[i]<<endl;
    }

    return 0;
}
