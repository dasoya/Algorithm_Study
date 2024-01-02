//
// Created by dasoya on 1/2/24.
//
#include<bits/stdc++.h>

using namespace std;

int vis[100002] = {};
int dx[3] = {1,-1,0};
int dy[3] = {1,1,2};

int main(void){

    int n,k;

    cin >> n >> k;

    //fill(vis[0],vis[n-1],-1);

    vis[n] = 1;
    vis[k] = -1;


    queue<int> Q;

    Q.push(n);

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 3; ++i) {
            int nx = cur *dy[i] + dx[i] ;
            if(nx <0 || nx > 100000) continue;
            if(vis[nx] >0) continue;

            Q.push(nx);
            vis[nx] = vis[cur]+1;
            //cout << "("<<nx << ','<< vis[nx] << ")";
            if(nx == k) break;
        }
    }


    cout << vis[k]-1;
}