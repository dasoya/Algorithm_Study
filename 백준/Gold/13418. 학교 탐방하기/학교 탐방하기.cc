//
// Created by dasoya on 10/30/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<pair<int,int>> adj[1002];
bool check[1002];

int main(){

    cin.tie(0);
    int n,m,a,b,c;
    cin >> n >> m;

    for(int i = 0 ; i <= m ; i++){
        cin >> a >> b >> c;

        if(c == 0) c = 1;
        else c = 0;

        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    //최대 최소
    priority_queue<tuple<int,int,int>> pq;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pqMin;

    int ansMax = 0,ansMin=0;

    for(auto nxt : adj[0]){
        pq.push({nxt.first,0,nxt.second});
        pqMin.push({nxt.first,0,nxt.second});
    }
    //오르막길이 1, 내리막길이 0
    check[0] = 1;

    //최대한 오르막길이 많게
    while(!pq.empty()){

        tie(c, a, b) = pq.top(); pq.pop();
        if(check[b]) continue;

        check[b] = 1;
        ansMax += c;
       // cout << a <<" " << b <<" | ";

        //cost, b
        for(auto nxt : adj[b]){
            if(!check[nxt.second])
            pq.push({nxt.first,b,nxt.second});
        }
    }


    fill(check,check+n+1,false);
    check[0] = 1;

    //최대한 내리막길이 많게
    while(!pqMin.empty()){

        tie(c, a, b) = pqMin.top(); pqMin.pop();
        if(check[b]) continue;

        check[b] = 1;
        ansMin += c; // ans Min은 결국 오르막길의 갯수 아닌가?
        // cout << a <<" " << b <<" | ";

        for(auto nxt : adj[b]){
            if(!check[nxt.second])
                pqMin.push({nxt.first,b,nxt.second});
        }
    }
   // cout << "\n";

    cout << ansMax*ansMax - ansMin*ansMin;

}