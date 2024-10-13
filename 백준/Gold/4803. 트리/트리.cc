//
// Created by dasoya on 10/8/24.
//
#include "bits/stdc++.h"

using namespace std;
vector<int> adj[501];

int solve(int n){

    int cnt = 0;
    bool vis[501];
    int p[501];

    fill(vis,vis+n+1,0);
    fill(p,p+n+1,0);

    for(int i = 1; i<=n ; i++){
        if(vis[i]) continue;

        bool isTree = true;
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int nxt: adj[cur]){
                if(vis[nxt] && nxt != p[cur]){
                    isTree = false;
                    break;
                }
                if(nxt == p[cur]) continue;

                q.push(nxt);
                vis[nxt] = true;
                p[nxt] = cur;
            }
        }

        if(isTree) cnt++;
    }

    return cnt;
}

int main(){
    int idx = 1;
    while(true){

        int n,m;

        cin >> n >> m;

        if(n==0 && m==0) break;
        int treeCount = 0;
        int u, v;

        for(int i = 0; i<= n;i++)
            adj[i].clear();

        while(m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        treeCount = solve(n);

        cout << "Case " << idx++<<": ";
        if(treeCount==0) {
            cout << "No trees." << "\n";
        }
        else if(treeCount ==1){
            cout << "There is one tree." << "\n";
        }else{
            cout << "A forest of "<<treeCount<<" trees." << "\n";
        }
    }

}