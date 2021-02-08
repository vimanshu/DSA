// wap to find the sssp(single source shortest path) in a *******tree
// i am going to use dfs
#include <iostream>
#include <vector>
using namespace std;
void sssp(vector<vector<int>> &graph, int curr,int currDis, vector<int> &visited,
          vector<int> &distance){
            visited[curr]=true;
            distance[curr]=currDis;
            for(int child: graph[curr]){
              if(visited[child]==false){
                sssp(graph,child,currDis+1,visited,distance);
              }
            }
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
  vector<int> distance(v,-1);
  sssp(graph,1,0,visited,distance);
  for (int i = 0; i < distance.size(); i++) {
    cout<<i<<"-> "<<distance[i]<<endl;
  }
}
/*
input: 
6 5
1 2
1 3
1 4
4 5
5 6 */
