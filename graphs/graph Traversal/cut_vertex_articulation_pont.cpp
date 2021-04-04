// wap for finding the cut-vertex or articulation point
#include <bits/stdc++.h>
using namespace std;
int visited_times=0;

void cut_vertex(vector<vector<int>> &graph,int curr, vector<int>&visited, vector<int>&in, vector<int>&low, int par, int timer){
    visited[curr]=true;
    in[curr]=timer;
    low[curr]=timer;
    timer++;
    for(int child:graph[curr]){
        if(child==par){
            continue;
        }
        else if(visited[child]==true){
            if(child!=par){
                low[curr]=min(low[curr],in[child]);
            }
        }
        else{
            //forward edge
            cut_vertex(graph,child,visited,in,low,curr,timer);
            low[curr]=min(low[curr],low[child]);
            if(in[curr]<=low[child] && par!=-1){
                cout<<"cut-vertex: "<<curr<<endl;
                visited_times++;
            }
        }
        
    }
    if(visited_times>=2 && par==-1){
        cout<<"cut-vertex: "<<curr<<endl;
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
    vector<int> in(v,-1);
    vector<int> low(v,-1); 
    int par=-1;
    int timer=1;
    cut_vertex(graph,1,visited,in,low,par,timer);
    cout<<visited_times<<endl;
    for (int i = 0; i < in.size(); i++) {
        cout<<in[i]<<" : "<<low[i]<<endl;
    }
}

/* input:
7 8
1 2
1 5
2 3
3 4
2 4
5 6
5 7
6 7
expected o/p:
cut-vertex: 2
cut-vertex: 5
cut-vertex: 1
2
-1 : -1
1 : 1
2 : 2
3 : 2
4 : 2
2 : 2
3 : 2
4 : 2
*/
