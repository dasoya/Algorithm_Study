//
// Created by dasoya on 11/12/24.
//
#include "bits/stdc++.h"
#define X first
#define Y second
using namespace std;

int n ,m, k;
vector<pair<int,int>> adj[100001];
vector<int> k_city;
long long d[100001];

const long long INF = INT64_MAX;
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;

void solve(){

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(d[cur.second] != cur.first) continue;

        for(auto nxt : adj[cur.second]){

            if(d[nxt.second] <= d[cur.second]+nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> k;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].emplace_back(w, u);
    }

    for (int i = 0; i < k; ++i) {
        int kt;
        cin >> kt;
        k_city.emplace_back(kt);
    }

    fill(d,d+n+1,INF);

    for(auto ki : k_city){
        d[ki] = 0;
        pq.push({d[ki],ki});
    }

    solve();

    int idx = max_element(d+1,d+n+1) -d;

    cout << idx << "\n" << d[idx];//<<"\n";

}