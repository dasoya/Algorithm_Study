//
// Created by dasoya on 10/24/24.
//
#include "bits/stdc++.h"

using namespace std;
vector<int> adj[32001];
int indegree[32001];
int main(){

    cin.tie(0);

    int n,m,x,y;
    cin >> n >> m;

    while(m--){
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    priority_queue<int,vector<int>,greater<>> pq;

    //vector<int> roots;
    for(int i=1;i<=n;i++)
       if(!indegree[i]) pq.push(i);

    while(!pq.empty()){

        int cur = pq.top(); pq.pop();
        cout << cur << " ";
        for(auto nxt : adj[cur]){
            indegree[nxt]--;

            if(indegree[nxt]==0){
                pq.push(nxt);
            }
        }
    }


}