//
// Created by dasoya on 10/15/24.
//

#include "bits/stdc++.h"

using namespace std;

int ans = 0;
vector<int> adj[100001];
vector<bool> vis(100001,false);

int grpNum = 0;
int cycle = 0;


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,u,v;
    cin >> n >> m;


   for(int i = 0; i < m ;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    //연결을 끊는. -> 사이클의 갯수
    //두 뉴련을 연결 -> 집합의 개수 -1 dfs 쉽게 구할 수 있음
    for(int i = 1; i <= n;i++){
        if(vis[i]) continue;

        ++grpNum;
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nxt: adj[cur]) {
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }

   // cout<<grpNum<<" ";
    cout << grpNum-1+m+grpNum-1 -(n-1);
}