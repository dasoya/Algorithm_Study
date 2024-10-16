//
// Created by dasoya on 10/16/24.
//

#include "bits/stdc++.h"

using namespace std;
int ans[100001];
vector<int> adj[100001];

void dfs(int cur,int w){

    ans[cur] += w;
    for(int nxt:adj[cur]){
       dfs(nxt,ans[cur]);
    }
}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,p,u,w;

    cin >> n >> m;

    for(int i = 1; i<=n;i++){
        cin >> p;
        if(p==-1) continue;
        adj[p].push_back(i);
    }

    while(m--){
        cin >> u >> w;
        ans[u] +=w;
    }

    dfs(1,0);

    for(int i = 1; i<=n;i++){
        cout << ans[i] <<" ";
    }

}