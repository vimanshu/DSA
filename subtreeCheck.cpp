// write a program to tell whether two nodes are subtree of any of them
// the use of in-out time concept
// IN TIME: when a vertex enters for the first time
// OUT TIME: when a vertex pops out

#include <iostream>
#include <vector>
using namespace std;
// timer should be used as call by reference
void subtree(vector<vector<int>> &graph, int curr, vector<int> & visited,vector<int> & in,vector<int> & out, int &timer){
  visited[curr]=true;
  in[curr]=timer;
  timer++;
  for(int child: graph[curr]){
    if(visited[child]==false){
      subtree(graph,child,visited,in,out,timer);
    }
  }
  out[curr]=timer;
  timer++;
}
bool check_subtree(int x, int y, vector<int> &in, vector<int> &out){
  if(in[x]>in[y] && out[x]<out[y] ||in[y]>in[x] && out[y]<out[x]){
    return true;
  }
  return false;
}
int main()
{
  int v,e;
  cin>>v>>e;
  v++;
  vector<vector<int>> graph(v,vector<int>(0));
  for (int i = 0; i < e; i++) {
    int s,d;
    cin>>s>>d;
    graph[s].push_back(d);
    graph[d].push_back(s);
  }
  vector<int> visited(v,false);
  vector<int> in(v,-1);
  vector<int> out(v,-1);
  int timer=1;
  subtree(graph,1,visited,in,out,timer);
for (int i = 1; i < in.size(); i++) {
  cout<<in[i]<<" ";
}
cout<<endl;
for (int i = 1; i < out.size(); i++) {
  cout<<out[i]<<" ";
}
int x,y;
cin>>x>>y;
cout<<endl;
cout<<"subtree-check-->"<<check_subtree(x,y,in,out);
    return 0;
}
