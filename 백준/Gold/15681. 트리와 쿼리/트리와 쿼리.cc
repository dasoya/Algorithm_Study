//
// Created by dasoya on 10/13/24.
//

#include "bits/stdc++.h"

using namespace std;


vector<int> adj[100001];
int ans[100001];

int dfs(int cur,int prev){

    int cnt = 1;
    for(int nxt: adj[cur]){

        if(nxt==prev) continue;

        cnt += dfs(nxt,cur);
    }

    ans[cur] = cnt;
    return cnt;
}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,r,q,u,v,query;

    cin >> n >> r >> q;

    for(int i =0; i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans[r] = dfs(r,-1);

    while(q--){
        cin >> query;
        cout << ans[query] << "\n";
    }
}