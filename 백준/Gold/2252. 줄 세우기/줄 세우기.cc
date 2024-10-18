//
// Created by dasoya on 10/18/24.
//

#include "bits/stdc++.h"

using namespace std;
vector<int> adj[32001];
int indegree[32001];


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,u,v;
    cin >> n >> m;

    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for(int i = 1 ;i <=n;i++){

        if(indegree[i]!=0) continue;
        //cout << i <<" ";
        q.push(i);

    }

    while(!q.empty()){

        int i = q.front();
        cout << i << " ";
        q.pop();

        for (int nxt : adj[i]) {
            indegree[nxt]--;
            if(indegree[nxt]==0){
                q.push(nxt);
            }
        }
    }





}