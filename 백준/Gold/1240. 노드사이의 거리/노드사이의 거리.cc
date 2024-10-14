//
// Created by dasoya on 10/14/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<pair<int,int>> adj[1001];
int ans = 0;

void dfs(int u,int v,int total,int prev){

    if(u==v){
        ans = total;
    }

    for (auto nxt :adj[u]) {

        if(nxt.first == prev) continue;
        dfs(nxt.first,v,total+nxt.second,u);
    }

    return ;
}

int main(){

    int n,m,u,v,dis;
    cin >> n >> m;

    while(n-- !=1){
        cin >> u >> v >> dis;
        adj[u].push_back({v,dis});
        adj[v].push_back({u,dis});
    }

    while(m--){
        cin >> u >> v;
        dfs(u,v,0,-1);
        cout << ans << "\n";
    }
}