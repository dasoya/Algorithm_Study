//
// Created by dasoya on 11/11/24.
//

#include "bits/stdc++.h"
#define X first
#define Y second

using namespace std;

vector<pair<int,int>> adj[801];
int d[801];
int n,m,v1,v2;
const int INF = 0x3f3f3f3f;

int solve(int st,int en){
    fill(d,d+n+1,INF);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){

        auto cur = pq.top(); pq.pop();

        if(cur.first != d[cur.second]) continue;

        for(auto nxt : adj[cur.Y]){
            if(d[nxt.second] <= d[cur.Y] + nxt.first) continue;
            d[nxt.second] = d[cur.Y] + nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

    return d[en];
}

int main(){


    cin >> n >> m;

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    cin >> v1 >> v2;

    //v1,v2사이에 순서는 상관없음.
    //두개의 경로르 보면 됨. 1- v1 - v2 - n / 1 - v2 - v1 - n
    long long ans = INF;

    long long fixed = solve(v1,v2);
    long long fixed2 = solve(v2,v1);
    ans = min(solve(1,v1)+ fixed + solve(v2,n),solve(1,v2)+ fixed2 + solve(v1,n));

    if(ans>=INF) ans = -1;
    cout << ans;


}