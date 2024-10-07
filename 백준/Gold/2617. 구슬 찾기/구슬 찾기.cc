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

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n , m;
    int ans = 0;

    cin >> n >> m;

    int h,l;

    while(m--){
        cin >> h >> l;
        adj[l].push_back(h);
        adj_l[h].push_back(l);
    }

    for(int i = 1; i <= n;i++){

        fill(cost,cost+n+1,-1);

        queue<int> q;
        q.push(i);
        cost[i] = 0;

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nxt: adj[cur]){
                if(cost[nxt] != -1) continue;

                q.push(nxt);
                cost[nxt] = cost[cur]+1;

                if( cost[nxt] > 0) {
                    lighter[nxt]++;
                }
            }
        }
    }

    for(int i = 1; i<=n;i++){

        fill(cost,cost+n+1,-1);

        queue<int> q;
        q.push(i);
        cost[i] = 0;

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nxt: adj_l[cur]){
                if(cost[nxt]!=-1) continue;

                q.push(nxt);
                cost[nxt] = cost[cur]+1;

                if(cost[nxt]>0) {
                    heavier[nxt]++;
                }
            }
        }
    }

    for(int i = 1; i<=n;i++){

        if(lighter[i] >n/2)
            ans++;
        else if (heavier[i]>n/2)
            ans++;
    }

    cout << ans;



}