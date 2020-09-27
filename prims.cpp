#include<bits/stdc++.h>
using namespace std;
class Prims {
    public:
       
        vector<vector<int>> edge;
        map<pair<int,int>,int> cost;
        Prims(int n) {
            edge.resize(n);    
        }

        void addEdge(int source,int destination,int weight) {
            edge[source].push_back(destination);
            cost[{source,destination}]=weight;
            edge[destination].push_back(source);
            cost[{destination,source}]=weight;
            
        }
        int prims() {
            vector<int> visited(edge.size(),false);
            map<int,vector<pair<int,int>>> queue;
            int totalCost=0;
            int count=0;
            for(int i=0;i<edge[0].size();i++) {
                queue[cost[{0,edge[0][i]}]].push_back({0,edge[0][i]});
            } 
            
            while(count!=edge.size()-1) {
                auto itr=queue.begin();
                while(visited[itr->second[itr->second.size()-1].second]) {
                    itr->second.pop_back();
                    if(itr->second.size()==0) {
                        queue.erase(itr);
                        itr=queue.begin();
                    }
                }
                int costOfEdge=itr->first;
                pair<int,int> p=itr->second[itr->second.size()-1];
                itr->second.pop_back();
                if(itr->second.size()==0) {
                    queue.erase(itr);
                }
                cout<<p.first<<"->"<< p.second<<": "<<costOfEdge<<endl;
                totalCost+=costOfEdge;
                visited[p.first]=true;
                visited[p.second]=true;
                for(int i=0;i<edge[p.second].size();i++) {
                    if(!visited[edge[p.second][i]]) {
                        queue[cost[{p.second,edge[p.second][i]}]].push_back({p.second,edge[p.second][i]});
                    }
                }

                count++;
            }
            
            return totalCost;
        }   
};
int main() {
   
    int edgeCount;
    int vertices;
    cin>>vertices>>edgeCount;
     Prims p=Prims(vertices);
    while(edgeCount--) {
        int source,destination,weight;
        cin>>source>>destination>>weight;
        p.addEdge(source,destination,weight);
    }
   
    // int count=0;
    // for(auto x:p.edge) {
    //     cout<<count++<<":";
    //     for(auto l:x) {
    //         cout<<l<<" ";
    //     }
    //     cout<<endl;
    // }
    int result=p.prims();
    cout<<"Minimum Cost:"<<result;
    return 0;
}