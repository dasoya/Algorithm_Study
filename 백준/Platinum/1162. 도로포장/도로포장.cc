//
// Created by dasoya on 1/8/25.
//


#include "bits/stdc++.h"
#define ll long long

using namespace std;

vector<tuple<ll,int,int>> adj[10001];
const int KMX = 20;
const int NMX = 10'000;
ll d[KMX + 2][NMX + 2];
int INF = 0x3f3f3f3f;
int n,m,k;

ll solve(){

   // for(int i = 0; i<= k;i++)
        //fill(d[i],d[i]+n,INF);

    memset(d, 0x3f, sizeof(d));

    for(int i = 0; i <= k; i++)
        d[i][1] = 0;

    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq;//cost,b,k, -된 거리
    pq.push({0,1,0});

    while(!pq.empty()){

        auto[c,b,usedK] = pq.top(); pq.pop();

        if(d[usedK][b] != c) continue;

        for(auto [nc,nxt,nk]: adj[b]){

            nk += usedK;
            nc += c;
            if (nk > k) continue;
            if(d[nk][nxt] <= nc) continue;
            d[nk][nxt] =  nc;
            pq.push({d[nk][nxt], nxt, nk});

        }


    }

    ll ans =0x3f3f3f3f3f3f3f;

    for(int i = 0; i<=k;i++){
        ans = min(ans,d[i][n]);
    }
    return ans;


}

int main(){

    cin >> n >> m >> k;

    for(int i = 0 ; i < m ;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b,0});
        adj[b].push_back({c,a,0});

        adj[a].push_back({0,b,1});
        adj[b].push_back({0,a,1});
    }

    cout << solve();
    //mCk

}