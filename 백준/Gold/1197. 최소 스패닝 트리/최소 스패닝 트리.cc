//
// Created by dasoya on 10/26/24.
//

#include "bits/stdc++.h"

using namespace std;

//가중치, a,b
vector<tuple<int,int,int>> adj[10001];
bool mst[10001];

int main(){

    int v,e;

    cin >> v>> e;

    //가중치 , a,b
    //vector<tuple<int,int,int>> edges;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

    int a,b,c;

    for(int i =0;i<e;i++){
        cin >> a >> b >> c;
        adj[a].emplace_back(c,a,b);
        adj[b].emplace_back(c,b,a);
    }

    //프림 알고리즘
    //점에 연결된 간선을 알아야함.

    int ans = 0, cnt =0;


   // for(int i = 1 ;i<=v;i++){
       //
       int cur = 1;

       while(cnt != v-1) {
           mst[cur] = true;
           cnt++;

           for (auto nxt: adj[cur]) {
               pq.push(nxt);
           }

           int costE,ea,eb,pre = cur;

           while(cur == pre){
               tie(costE,ea,eb) = pq.top(); pq.pop();
               if(mst[eb]) continue;
               ans += costE;
               mst[eb] = true;
               cur = eb;
           }

       }

       cout << ans;

   // }


}