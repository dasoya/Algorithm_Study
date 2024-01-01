
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[502][502]  = {0};
bool vis[502][502] = {false};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int main(){
    cin >> n >> m ;

    queue<pair<int,int>> Q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j] ;
        }
    }

    int res1=0, res2 =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(vis[i][j]) continue;
            if(board[i][j]==0) continue;
            Q.push({i,j});
            vis[i][j] = true;
            res1++;
            //cout << "{"<<i<<","<<j<<"}";
            int res2_temp = 0;
            while(!Q.empty()){

                pair<int,int> cur = Q.front(); Q.pop();

                vis[cur.first][cur.second] = true;
                res2_temp++;
                //cout << "{"<<cur.first<<","<<cur.second<<"}";

                for(int k=0; k<4; k++){

                    if(cur.first +dx[k] <0 || cur.second+dy[k] < 0 || cur.first+dx[k]>n-1 || cur.second+dy[k] > m-1 ) continue;
                    if(board[cur.first+dx[k]][cur.second+dy[k]]==0) continue;
                    if(vis[cur.first+dx[k]][cur.second+dy[k]]) continue;

                    Q.push({cur.first+dx[k],cur.second+dy[k]});
                    vis[cur.first+dx[k]][cur.second+dy[k]] = true;
                    //cout << cur.first+k << cur.second+k;
                }
            }

            if(res2<=res2_temp) res2=res2_temp;
            //cout << "res2: "<< res2 << "\n";
        }
    }

    cout << res1 << "\n" << res2;
    return 0;
}


