//
// Created by dasoya on 10/29/24.
//
#include "bits/stdc++.h"

using namespace std;

int mat[1002][1002];
bool check[1002];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;

    cin >> n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> mat[i][j];


    long long ans = 0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    check[1] = 1;
    for(int i = 1; i <= n;i++){
        if(i == 1) continue;
        pq.push({mat[1][i],1,i});
    }
    
    int cost,a,b;
    while(!pq.empty()){
        tie(cost,a,b) = pq.top(); pq.pop();
        if(check[b]) continue;

        ans+=cost;
        check[b] = 1;

        for(int i = 1; i <= n;i++){
            if(i == b || check[i]) continue;
            if(mat[b][i] != 0) pq.push({mat[b][i],b,i});
        }

    }

    cout << ans;

}