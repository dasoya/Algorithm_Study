//
// Created by dasoya on 1/13/24.
//

#include <bits/stdc++.h>

using namespace std;


int board[102][102]={};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(void){
    int visit[102][102]={};

    int n,m,k;

    cin >> n>>m>>k;

    for (int i = 0; i < k; ++i) {
        int x1,y1,x2,y2;
        cin >> x1>>y1>>x2>>y2;

        for (int j = y1; j < y2; ++j) {
            fill(board[j]+x1,board[j]+x2,1);
        }

    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//
//           cout<< board[i][j] << " ";
//        }
//        cout<<"\n";
//    }

    queue<pair<int,int>> Q;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if(board[i][j]==1||visit[i][j]==1) continue;

            Q.push({i,j});
            visit[i][j] = 1;
            int result = 1;

            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();

                for (int l = 0; l < 4; ++l) {
                    int nx = cur.first + dx[l];
                    int ny = cur.second + dy[l];

                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(board[nx][ny]==1||visit[nx][ny]==1) continue;

                    Q.push({nx,ny});
                    visit[nx][ny] = 1;
                    result++;

                }
            }

            v.push_back(result);
        }
    }

    cout<< v.size()<<"\n";

    sort(v.begin(),v.end());

    for (int i = 0; i < v.size(); ++i) {
        cout<< v[i]<<" ";
    }




}