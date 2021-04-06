// doing a bfs traversal in graph

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &graph,int v){
    vector<int> visited(v);
    queue<int> q;
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int child:graph[curr]){
            if(visited[child]==false){
                visited[child]=true;
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
        int s,d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    
    bfs(graph,v);

    return 0;
}
