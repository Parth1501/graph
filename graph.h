#include<bits/stdc++.h>
using namespace std;
class Graph {
    public:
    vector<vector<int>> edge;
    map<pair<int,int>,int> cost;
    int size;
    Graph(int size) {
        this->size=size;
        edge.resize(size);
    }
    void addEdge(int source,int destination,int weight) {
        edge[source].push_back(destination);
        edge[destination].push_back(source);
        cost[{source,destination}]=weight;
        cost[{destination,source}]=weight;
    }
    int edgeCost(int source,int destination) {
        if(cost.find({source,destination})!=cost.end()) {
            return cost[{source,destination}];
        }
        else if(cost.find({destination,source})!=cost.end()) {
            return cost[{destination,source}];
        }
        else {
            return -1;
        }
    }
 };
