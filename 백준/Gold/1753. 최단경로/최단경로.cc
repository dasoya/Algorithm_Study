//
// Created by dasoya on 11/5/24.
//


#include "bits/stdc++.h"

using namespace std;

const int INT = 0X3f3f3f;
int main(){

    vector<pair<int,int>> adj[20001];
    int dis[20001];

    int n,m,a,b,cost,k;
    cin >> n >> m >> k;

    while(m--){
        cin >> a >> b >> cost;
        adj[a].push_back({b,cost});
    }

    fill(dis,dis+n+1,INT);

    //1에서 부터 시작하면

    int cnt = 1;
    int cur = k;
    dis[k] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    pq.push({0,cur});

    int node;
    //cnt, nxt
    while(!pq.empty()){
        tie(cost,node) = pq.top(); pq.pop();

        if(dis[node]==cost){
            cnt++;
            for(auto nxt : adj[node]){
                if(dis[nxt.first] > nxt.second+dis[node])
                {
                    dis[nxt.first] = nxt.second+dis[node];
                    pq.push({dis[nxt.first],nxt.first});
                }
            }
        }
    }

    for(int i = 1 ; i <= n;i++){
      if(dis[i]==INT)  cout << "INF" <<"\n";
      else cout << dis[i] <<"\n";
    }

}


