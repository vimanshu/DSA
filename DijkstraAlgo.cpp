// dijkstra algorithm
// single source shortest path

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
void dijkstra(vector<vector<pair<int,int>>> &graph,int v,int source,vector<int> &distance,
                vector<int> &visited){
      //need a priority queue
      priority_queue <pair<int,int>> q;
      distance[source]=0;
      q.push({distance[source],source}); //source=0 and dis[source]=0
      // need to visit every node/vertices in the graph
      
      while(!q.empty()){
        // get the min from the priority queue
         pair<int,int> p_min=q.top();
        q.pop(); //delete the first element in queue
        if(p_min.second==true){
          continue;
        }
        
        visited[p_min.second]=true;
          // i need to visit every adjacent element of this source
          for(pair<int,int> child:graph[p_min.second]){
             int wt= child.first; // weight of source/node 
            int d= child.second; // destination of source/node
            if(visited[d]==false){
           if(wt+distance[p_min.second]<distance[d]){
               // condition for relaxing of the length
              distance[d]=wt+distance[p_min.second];
              q.push({-distance[d],d});
            }
            }
          }
        
        
      }
      //return distance;
      for (int i = 0; i < distance.size(); i++) {
          cout<<distance[i]<<" ";
            }
}
int main(){
  int v,e;
  cin>>v>>e;
  vector<vector<pair<int,int>>> graph(v, vector<pair<int,int>>(0,{0,0}));
  for (int i = 0; i < e; i++) {
    int s,d,wt;
    cin>>s>>d>>wt;
    graph[s].push_back({wt,d});
    graph[d].push_back({wt,s});
    //bidirectional graph
  }
  //after taking the input ab kya krna hai?
  vector<int> distance(v, INT_MAX);
  vector<int> visited(v,false);
  int source;
  cin>>source;
dijkstra(graph,v,source,distance,visited);

}

/* 
input:
5 7
0 1 20
0 3 10
0 2 40
1 2 30
2 4 50
4 3 20
3 2 10
0
*/
