// wap to find if the graph is bi-partite or not
// i am going to use dfs
#include <iostream>
#include <vector>
using namespace std;
bool sssp(vector<vector<int>> &graph, int curr,int currCol, vector<int> &visited,
          vector<int> &color){
            visited[curr]=true;
            color[curr]=currCol;
            for(int child: graph[curr]){
              if(visited[child]==false){
                if(sssp(graph,child,!currCol,visited,color)==false){
                  return false;
                  
                }
              }
              if(visited[child]==true){
                if(color[child]==color[curr]){
                  return false;
                }
              }
            }
            return true;
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
  vector<int> color(v,-1);
  cout<<sssp(graph,1,0,visited,color);
  
}
/* 
input:
4 5
1 2
1 3
2 4
3 4
1 4
*/
