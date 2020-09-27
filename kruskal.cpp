#include"graph.h"

bool compare(pair<pair<int,int>,int> c1,pair<pair<int,int>,int> c2) {
    return c1.second>c2.second;
}
vector<pair<pair<int,int>,int>> sortMap(map<pair<int,int>,int> &m) {
    vector<pair<pair<int,int>,int>> v;
    for(auto x:m) {
        pair<pair<int,int>,int>  p;
        p.first=x.first;
        p.second=x.second;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),compare);
    return v;
}
int parentNode(int node,vector<int> & parent) {
    if(parent[node]==node) {
        return node;
    }
    return parentNode(parent[node],parent);

}

int kruskal(Graph &g) {
    vector<pair<pair<int,int>,int>> sorted=sortMap(g.cost);
    vector<int> parent(g.edge.size());
    set<pair<int,int>> s;
    int totalCost=0;
    for(int i=0;i<g.edge.size();i++) {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(i<g.edge.size()||count!=g.edge.size()-1) {
            pair<pair<int,int>,int> currentEdge=sorted.back();
            int sourceParent=parentNode(currentEdge.first.first,parent);
            int destinationParent=parentNode(currentEdge.first.second,parent);
            if(sourceParent!=destinationParent) {
                cout<<currentEdge.first.first<<"->"<<currentEdge.first.second<<":"<<currentEdge.second<<endl;
                parent[sourceParent]=destinationParent;
                count++;
                totalCost+=currentEdge.second;
            }
            i++;
        sorted.pop_back();
    }
    return totalCost;
}
int main() {
    Graph g=Graph(6);
    g.addEdge(0,1,4);
    g.addEdge(0,2,3);
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    g.addEdge(2,3,4);
    g.addEdge(3,4,2);
    g.addEdge(4,5,6);

  
    int result=kruskal(g);
    cout<<endl;
    cout<<result;
}