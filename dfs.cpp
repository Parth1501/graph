#include<bits/stdc++.h>
using namespace std;
class DFS {
    public:
    vector<vector<int>> edge;
    
    vector<bool> visited;
    DFS(int size) {
        edge.resize(size);
        visited.resize(size);
        fill(visited.begin(),visited.end(),false);
    }
    void addEdge(int u,int v) {
        edge[u].push_back(v);
    }
    void dfs(int u) {
        if(visited[u]==false) {
            visited[u]=true;
            for(int i=0;i<edge[u].size();i++) {
                dfs(edge[u][i]);
            }
        }
    }
    
};
int main() {
    
    DFS g=DFS(7);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    // g.addEdge(5, 6); 
     
    g.addEdge(6, 0);
    int last=0;
    for(int i=0;i<7;i++) {
        if(!g.visited[i]) {
            last=i;
            g.dfs(i);
        }
    }
    fill(g.visited.begin(),g.visited.end(),false);
    g.dfs(last);
    for(int i=0;i<7;i++) {
        if(!g.visited[i]) {
            cout<<"No mother node";
            return 0;
        }
        
    }
    
    cout<<last;
}