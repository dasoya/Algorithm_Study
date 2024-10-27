//
// Created by dasoya on 10/27/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<pair<int,int>> adj[305];
bool check[305];
int main(){

    int n, cost;
    cin >> n;

    for(int i=0; i<n;i++){
        cin >> cost;
        adj[n].emplace_back(cost,i);
        adj[i].emplace_back(cost,n);
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin >> cost;
            if(cost==0) continue;
            adj[i].emplace_back(cost,j);
            adj[j].emplace_back(cost,i);
        }
    }


    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

    vector<int> mst;
    int ans = 0;

    mst.emplace_back(0);
    check[0] = true;

    for(auto nxt: adj[0]){
        pq.push({nxt.first, 0,nxt.second});
    }

    while(mst.size()<=n){
        int cst,a,b;
        tie(cst,a,b) = pq.top(); pq.pop();

        if(check[b]) continue;

        ans+=cst;
        check[b] = true;
        mst.push_back(b);
       // cout << b <<" ";

        for(auto nxt: adj[b]){
            if(!check[nxt.second])
            pq.push({nxt.first, b,nxt.second});
        }


    }

    cout << ans;

}