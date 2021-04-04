// finding cut-edge in the graph- that the graph gets disconnected by cutting an edge


#include <bits/stdc++.h>
#include <vector>
using namespace std;

void cut_edge(vector<vector<int>> &graph, int curr, vector<int> &visited, vector<int>&in, vector<int>&low, int par, int timer){
    visited[curr]=true;
    in[curr]= timer;
    low[curr]=timer;
    for(int child: graph[curr]){
        if(child==par){
            continue;
        }
        else if(visited[child]==true){
            if(child!=par){
                low[curr]=min(low[curr],in[child]);
            }
        }
        else{
            // not visited and not immediate parent
            cut_edge(graph,child,visited,in,low,curr,timer+1);
            if(low[child]>in[curr]){
                cout<<curr<<"--bridge--"<<child<<endl;
            }
            low[curr]=min(low[curr],low[child]);
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
    vector<int> in(v,-1);
    vector<int> low(v,-1); // update the low when we get the backedge
    int par=-1;
    int timer=1;
    cut_edge(graph,1,visited,in,low,par,timer);
    for (int i = 1; i < in.size(); i++) {
        cout<<i<<": "<<in[i]<<"->"<<low[i]<<endl;
    }
    return 0;
}

/*
input:
7 8
1 2
1 5
2 3
2 4
3 4
4 5
5 6
5 7
expected output:
5--bridge--6
5--bridge--7
1: 1->1
2: 2->1
3: 3->1
4: 4->1
5: 5->1
6: 6->6
7: 6->6
*/
