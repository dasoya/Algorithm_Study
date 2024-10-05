//
// Created by dasoya on 10/5/24.
//

#include "bits/stdc++.h"

using namespace std;;
int mat[101][101];
bool vis[101][101];
bool ans[101][101];
int main(){

    int n;
    cin >> n;


    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n;j++){
            cin >>  mat[i][j];
        }
    }

    for(int i = 1; i<=n ;i++){

        queue<int> q;
        q.push(i);
        for(int k=0;k<=n;k++)
        fill(vis[k],vis[k]+n+1,false);
        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int j = 1; j <= n ;j++){
                if(!mat[cur][j] || vis[cur][j]) continue;

                vis[cur][j] = true;
                ans[i][j] = true;
                q.push(j);
            }
        }

    }

    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n;j++){
            cout <<  ans[i][j]<<" ";
        }
        cout <<"\n";
    }


}