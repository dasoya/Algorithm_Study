//
// Created by dasoya on 10/7/24.
//

#include "bits/stdc++.h"

using namespace std;

int lighter[101];
int heavier[101];

int cost[101];
vector<int> adj[101];
vector<int> adj_l[101];
int N;

bool bfs(int i,vector<int> adj[]){

    int cnt = 0;
    fill(cost,cost+100+1,-1);

    queue<int> q;
    q.push(i);
    cost[i] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int nxt: adj[cur]){
            if(cost[nxt] != -1) continue;

            q.push(nxt);
            cost[nxt] = cost[cur]+1;
            cnt++;

        }
    }

    return cnt > N/2;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n , m;
    int ans = 0;

    cin >> n >> m;

    int h,l;

    N =n ;

    while(m--){
        cin >> h >> l;
        adj[l].push_back(h);
        adj_l[h].push_back(l);
        //중복해서 들어올 수 있음.
    }


    for(int i = 1; i<=n;i++){

        if(bfs(i,adj) || bfs(i,adj_l))
            ans++;

    }

    cout << ans;



}