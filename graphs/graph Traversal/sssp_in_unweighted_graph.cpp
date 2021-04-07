// single source shortest path in an unweighted graph

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &graph, int curr, vector<int> &visited, vector<int> &lvl, int currlvl){
    
    queue<int> q;
    q.push(curr);
    visited[curr]=true;
    lvl[curr]=currlvl;
    while(q.empty()==false){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(int child: graph[temp]){
            if(visited[child]==false){
                
                visited[child]=true;
                lvl[child]=lvl[temp]+1; // purana level +1
                q.push(child);
                
            }
                
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
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        // for undirected graph
    }
    
    // to find sssp we'll use bfs
    vector<int> visited(v,false);
    vector<int> lvl(v,-1);
    
    bfs(graph,1,visited,lvl,0);
    cout<<endl;
     for (int i = 1; i < v; i++) {
         cout<<i<<"->"<<lvl[i]<<endl;
     }

    
    return 0;
}
/* input:
6 7
1 2
1 3
1 6
2 4
2 5
3 5
6 5
*/
