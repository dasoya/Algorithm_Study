//
// Created by dasoya on 10/4/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<int> adj[1001];
bool vis[1001];
void dfs(int v){

    if(vis[v]) return;
    cout << v <<" ";
    vis[v]= true;
    for(auto nxt:adj[v]){
        dfs(nxt);
    }

    return;

}

void bfs(int v){

    queue<int> q;

    q.push(v);
    vis[v]= true;



    while(!q.empty()){

        int cur = q.front(); q.pop();

        cout << cur << " ";
        for(auto nxt: adj[cur]){

            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt]= true;


        }
    }



}

int main(){

    int n,m,stV,u,v;

    cin >> n >> m >> stV;

    while(m--){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int i = 1; i <= n ; i++){
        sort(adj[i].begin(),adj[i].end());
    }

    dfs(stV);

    cout << "\n";
    fill(vis,vis+1001,false);
    bfs(stV);

}