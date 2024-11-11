//
// Created by dasoya on 11/11/24.
//

#include "bits/stdc++.h"

using namespace std;
#define X first
#define Y second

//vector<int> adj[1000];
int d[101][101];
string mat[101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int INF = 0x3f3f3f3f;

int main(){

    int n,m;
    string s;

    cin >> m >> n;//가로 크기 - 열의 사이즈

    for(int i = 1; i <= n ; i++){
        cin >> s;
        mat[i] = ' '+s;
    }

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

    for(int i = 0; i <= n ; i++)
        fill(d[i],d[i]+m+1,INF);

    pq.push({0,1,1});
    d[1][1] = 0;
    int a,b,cost;


    while(!pq.empty()){

        tie(cost,a,b) = pq.top(); pq.pop();

        if(d[a][b] != cost) continue;

        for(int dir = 0 ; dir < 4; dir++){

            int nx = a + dx[dir];
            int ny = b + dy[dir];

            if(nx <= 0 || ny <= 0  || nx > n || ny > m) continue;
            if(d[nx][ny] <= d[a][b]+ (mat[nx][ny]-'0')) continue;
            d[nx][ny] = d[a][b]+(mat[nx][ny]-'0');
            pq.push({d[nx][ny],nx,ny});
        }

    }

    for(int i = 1; i <= n ; i++){

        for(int j = 1;j <= m; j++){
           //cout << d[i][j] << " ";
        }
       // cout <<"\n";
    }


    cout << d[n][m];

}