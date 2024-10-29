//
// Created by dasoya on 10/29/24.
//
#include "bits/stdc++.h"

using namespace std;

vector<int> adj[1001];
bool check[1001];

int main(){

    int t;
    cin >> t;

    while(t--){

        int n,m,a,b;
        cin >> n >> m;

        for(int i = 0;i<=n;i++) {adj[i].clear(); check[i] = false; }

        for(int i=0;i<m;i++){
            cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        int ans = 0; // 추가한 간선의 갯수를 구하는 것임.
        check[1] = 1;
        //프림 알고리즘
        for(auto nxt : adj[1]){
            pq.push({1,nxt});
        }

        while(!pq.empty()){

            auto cur = pq.top(); pq.pop();
            if(check[cur.second]) continue;
            ans++;
            check[cur.second] = 1;
            for(auto nxt : adj[cur.second]){
                if(check[nxt]) continue;
                pq.push({cur.second,nxt});
            }


        }

        cout << ans <<"\n";

    }

}