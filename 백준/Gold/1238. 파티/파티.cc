//
// Created by dasoya on 11/9/24.
//

#include "bits/stdc++.h"
using namespace std;

vector<pair<int,int>> adj[1002];
int d[1002];
int n,m,x;

int solve(int st,int end){
    int INF = 0x3f3f3f3f;
    fill(d,d+n+1,INF);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second] != cur.first) continue;

        for(auto nxt : adj[cur.second]){
            if(d[nxt.second] <= d[cur.second]+nxt.first) continue;
            d[nxt.second] = d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

    return d[end];

}

int main(){


    cin >> n >> m >> x;

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

  
   int ans = 0;

    for(int i = 1; i <=n;i++)
        ans = max(ans, solve(x,i)+solve(i,x));
    //아 오고간 시간이 최대.
    cout << ans;
}