//graph revision
// dfs traversal

#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &graph, int curr, vector<int> &visited){
  visited[curr]=true;
  cout<<"access route- "<<curr<<endl;
  for(int child:graph[curr]){
    if(visited[child]==false){
      
       dfs(graph,child,visited); // use of return and no return
    }
   
  }
  cout<<"exit route- "<<curr<<endl;
}
int main()
{
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
  dfs(graph,1,visited);
  

    return 0;
}

/* input:
4 4
1 2
1 3
1 4
2 3
*/
