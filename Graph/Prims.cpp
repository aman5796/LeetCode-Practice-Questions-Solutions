#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,int>>> graph;
    while(m--) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    priority_queue<pair<int,int>> pq;
    int cost=0;
    pq.push({0,1});
    vector<bool> visited(n+1,false);
    while (!pq.empty())
    {
       pair<int,int> node = pq.top();
       pq.pop();
       if(!visited[node.second]) {
           cost += -node.first;
            visited[node.second] = true;
            for(int i=0;i<graph[node.second].size();i++) {
                if(!visited[graph[node.second][i].first]) {
                    pq.push({-graph[node.second][i].second,graph[node.second][i].first});
                }
            }
       }
       if(pq.empty()) {
           for(int i=1;i<=n;i++) {
               if(!visited[i]) {
                   bool anyVertexPushed = false;
                   int minWt = INT_MAX;
                   for(int j=0;j<graph[i].size();j++) {
                       if(!visited[graph[i][j].first]) {
                           pq.push({-graph[i][j].second,graph[i][j].first});
                           anyVertexPushed = true;
                       }
                       minWt = min(minWt,graph[i][j].second);
                   }
                   visited[i] = true;
                   if(!anyVertexPushed) {
                       cost += minWt;
                   }
               }
           }
       }
    }
    cout<<cost;
    return 0;
}