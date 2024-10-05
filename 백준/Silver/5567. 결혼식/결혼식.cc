//
// Created by dasoya on 10/5/24.
//
#include "bits/stdc++.h"

using namespace std;

int vis[501];
vector<int> adj[501];

int main(){

    int n,m,u,v;
    cin >> n >> m;

    while(m--){

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){

        int cur = q.front(); q.pop();

        for(int nxt : adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = vis[cur]+1;
            if(vis[nxt]<4) ans++;
        }
    }

    cout << ans;

}