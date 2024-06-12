//
// Created by dasoya on 1/3/24.
//

#include <iostream>
//#include <bits/stdc++.h>
#include "queue"

using namespace std;

int dist[302][302];

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int main() {

    int k ;

    cin >>k;

    while(k--){
        queue<pair<int,int>> Q ;
        int n,kx,ky,a,b;
        cin >> n;
        for(int i =0; i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = -1;

            }
        }

        cin >> kx >> ky;
        cin >> a>>b;

        Q.push({kx,ky});
        dist[kx][ky] = 0;
        // dist[a][b] = -2;
        bool clear = false;
        while(!Q.empty()&&!clear){

            auto cur = Q.front(); Q.pop();

            if(cur.first==a&&cur.second==b){
                cout << dist[a][b] << "\n";
                clear = true;
                break;
            }

            for(int i=0; i<8;i++){

                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx<0|| nx > n || ny <0 || ny>n) continue;
                if(dist[nx][ny] >0 ) continue;

                Q.push({nx,ny});
                dist[nx][ny] = dist[cur.first][cur.second]+1;


            }

        }

    }

    return 0;

}