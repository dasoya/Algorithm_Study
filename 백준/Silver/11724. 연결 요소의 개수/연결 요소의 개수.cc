//
// Created by dasoya on 10/4/24.
//

#include "bits/stdc++.h"

using namespace std;

bool visited[1001];

int main(){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);

    int u,v;


    while(m--){

        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

    }

    int ans = 0;
    for(int i = 1; i <= n ; i++){

        if(visited[i]) continue;

        ans++;

        queue<int> q;

        q.push(i);

        while(!q.empty()){

            int cur = q.front(); q.pop();

            for(int j = 0; j < g[cur].size(); ++j) {

                if(visited[g[cur][j]]) continue;
                visited[g[cur][j]] = true;
                q.push(g[cur][j]);

            }
        }


    }



    cout << ans;


}