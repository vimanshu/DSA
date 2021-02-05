// minimum spanning true using prims
// important concept for prim's was to give relaxation/updation of the length/weights 
// of the edges.
// prims deals with the vertices
// what is new to me is pair
#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;
void prims(vector<vector<pair<int,int>>> &graph, int v, int start){
 
  vector<int> visited(v,false);
  vector<int> distance(v,INT_MAX);
  
  priority_queue <pair<int,int>> q;
  distance[start]=0;
  q.push({distance[start],start});
  
  //while we visit every node 
  int c=0;
  int mst_cost=0;
  while(c<v){
    // get the min from the priority_queue
    pair<int,int> p_min=q.top();
    q.pop();
        if(visited[p_min.second]==true){
          continue;
        }
        mst_cost+=p_min.first;
        //cout<<mst_cost<<" mscos"<<endl;
        c++; // increase the count of nodes
        visited[p_min.second]=true;
        
        for(pair<int,int> child: graph[p_min.second]){
          int des= child.second;
          int wt= child.first;
          if(visited[des]==false){
            //relaxation of length
            if(wt<distance[des]){
              distance[des]=wt;
              q.push({-wt,des});
            }
          }
        }
  }
  cout<<abs(mst_cost)<<endl;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> graph(v,vector<pair<int,int>>(v,{0,0}));
    // take the input
    for (int i = 0; i < e; i++) {
      int s,d,wt;
      cin>>s>>d>>wt;
      graph[s].push_back({wt,d});
      graph[d].push_back({wt,s});
    }
    //display what have been given to the graph?
    // for (int i = 0; i < graph.size(); i++) {
    //   for (int j = 0; j < graph[i].size(); j++) {
    //     int f=graph[i][j].first;
    //     int s=graph[i][j].second;
    //     cout<<graph[i][j]<<f<<s;
    //   }
    // }
    int start;
    cin>>start;
    prims(graph,v,start);
    return 0;
}
