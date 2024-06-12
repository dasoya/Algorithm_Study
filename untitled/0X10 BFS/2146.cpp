//
// Created by dasoya on 1/23/24.
//
#include "iostream"
#include "queue"
#include "tuple"
#include "vector"
#include "algorithm"

using namespace std;

int board[102][102];
int dist[102][102];


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
    int prev[102][102];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            dist[i][j] = -1;
            prev[i][j] = -1;
        }

    }

    queue<pair<int,int>> Q;
    queue<tuple<int,int,int>> R;
    vector<int> ans;

    int island = 1;

    //섬구역 표시.번호는 2부터 시작.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if(board[i][j] != 1) continue;

            Q.push({i,j});
            island++;
            board[i][j] = island;
            dist[i][j] = 0;

            while(!Q.empty()){
                auto  cur = Q.front(); Q.pop();

                for (int k = 0; k < 4; ++k) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(board[nx][ny] != 1){
                        if(board[nx][ny]==0){
                            if(prev[nx][ny] != -1 && prev[nx][ny] !=island) { cout << 1; return 0;}
                            prev[nx][ny] = island;
                            dist[nx][ny] = 1;
                            R.push({nx, ny,island});
                        }
                        continue;
                    }
                    else {
                        Q.push({nx, ny});
                        board[nx][ny] = island;
                        dist[nx][ny] = 0;
                    }
                }
            }
        }
    }
//Debug
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//
//            cout << dist[i][j] <<" ";
//        }
//    cout << "\n";
//    }

  //  queue<pair<int,int>> R;


            while(!R.empty()){
                auto  cur = R.front(); R.pop();
                int x,y,ci;
                tie(x,y,ci) = cur;

                for (int k = 0; k < 4; ++k) {
                    int nx = x+ dx[k];
                    int ny = y + dy[k];

                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    //섬의 거리가 1이상이 이미 존재하면
                    if(dist[nx][ny] >= 1) {

                        if(prev[nx][ny]!=prev[x][y]) {

                            int curR= dist[nx][ny] + dist[x][y];
                            ans.push_back(curR);
                           // if(curR < result) result = curR;
                        }

                    }
                    else if(dist[nx][ny]==-1){
                        R.push({nx, ny,ci});
                        dist[nx][ny] = dist[x][y] +1;
                        prev[nx][ny] = prev[x][y];
                    }

                }

            }

            sort(ans.begin(),ans.end());
            cout << ans[0];

}





