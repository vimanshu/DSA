// creating a graph and finding the number of connected components


#include <bits/stdc++.h>

using namespace std;
void print_list(vector<vector<int>> &graph){
  for (int i = 0; i < graph.size(); i++) {
    cout<<i;
    for (int j = 0; j < graph[i].size(); j++) {
      cout<<"->"<<graph[i][j];
    }
    cout<<endl;
  }
}
void print_dfs(vector<vector<int>> &graph, int curr, vector<int> &visited){
  visited[curr]=true;
  //cout<<curr<<" ";
  for(int child: graph[curr]){
    if(visited[child]==false){
      // make a recursive call
      print_dfs(graph,child,visited);
    }
  }
}
int noOfConnectedComponents(vector<vector<int>>&graph,vector<int> &visited){
   int count=0;
  for (int i = 0; i < graph.size(); i++) {
    if(visited[i]== false){ // new connection 
        print_dfs(graph,i,visited);
        count++;
      }
  }
  return count;
}
int main()
{
   //first we need number of vertices and edges
   int v,e;
   cin>>v>>e;
   // need to crete an adjacency list and call it graph
   // the data structure for adjacency list is a 2d vector
    vector<vector<int>> graph(v,vector<int>(0));
    // now we need conncetions
    // or the edges
    for (int i = 0; i <e; i++) {
      int s,d; // two linking data will be given in terms of source and destination
      cin>>s>>d;
      // supposing the graph here is bi-directional graph
      graph[s].push_back(d); // here we are connecting s with d
      graph[d].push_back(s); // here we are connecting d with s
    }
    // the connecting process has been done
   // now if we need to print the adjacenecy list
   print_list(graph);
   cout<<endl;
   vector<int> visited(v, false); // making a visited array which contains the vertices with all false
   //print_dfs(graph,0,visited);
   
   // write a function to find the number of connected components
   cout<<noOfConnectedComponents(graph,visited);
    return 0;
}
/* i/p- 7 6
1 2
1 3
2 3
4 5
4 6
5 6 */
