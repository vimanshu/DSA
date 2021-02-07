// number of connected components in the graph


#include <iostream>
#include <vector>
using namespace std;
void dfs( vector<vector<int>> &graph,int curr, vector<int> &visited){
  visited[curr]=true;
  for(int child: graph[curr]){
    if(visited[child]==false){
      dfs(graph,child,visited);
    }
  }
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
    int c=0;

    for (int i = 1; i < v; i++) {
      if(visited[i]==false){
        //cout<<"working for i="<<i<<endl;
        dfs(graph,i,visited);
        c++;
      }
    }
    
    cout<<"number of connected components->"<<c<<endl;
    return 0;
}

/* input:
10 7
1 2
1 3
2 4
4 3
5 6
7 8
8 9
*/
