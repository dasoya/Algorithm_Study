//
// Created by dasoya on 10/29/24.
//

#include "bits/stdc++.h"

using namespace std;
vector<pair<int,int>> adj[100001];
bool check[100001];

int main(){

    int n,m;

    cin >> n >> m;

    int a,b,c;

    for(int i =0 ; i < m ; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    // mst 를 만들고 그중 간선의 비용이 가장 큰거를 지우면 됨.
    //최솟값이 보장 되나? 다른 방법은 모르겠으니 일단 이걸로 구현

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

    for(auto nxt : adj[1]){
        pq.push({nxt.second,1,nxt.first});
    }

    check[1] = true;
    int ans = 0;
    int maxE = 0;

    while(!pq.empty()){
        int cost,st,ed;
        tie(cost,st,ed) = pq.top(); pq.pop();

        if(check[ed]) continue;

        //cout << ed<<" ";
        check[ed] = true;
        ans += cost;
        if(cost > maxE) maxE = cost;

        for(auto nxt : adj[ed]){
            if(!check[nxt.first])
                pq.push({nxt.second,st,nxt.first});
        }

    }

    cout << ans - maxE;
}

//1 -> 3 -> 6 -> 2 -> 5

//7
