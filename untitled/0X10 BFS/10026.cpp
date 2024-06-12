


#include <iostream>
#include "queue"

using namespace  std;

int vis[102][102];
string board[102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
//define first x;
//#define second y;

int main(void){

    int n;

    cin >> n;

    for (int f = 0; f < n; ++f) {
        cin >> board[f];
        fill(vis[f],vis[f]+n,0);
    }


    queue<pair<int,int>> q;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if(vis[i][j]) continue;

            q.push({i,j});
            vis[i][j] = 1;
            result++;

            while(!q.empty()){
                auto cur = q.front(); q.pop();

                for (int k = 0; k < 4; ++k) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx<0 ||nx >n || ny <0 ||ny >n) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] != board[cur.first][cur.second]) continue;

                    vis[nx][ny] =1 ;
                    q.push({nx,ny});

                }
            }

        }
    }

    int result2 = 0;

    for (int f = 0; f < n; ++f) {
        fill(vis[f],vis[f]+n,-1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if(vis[i][j]!=-1) continue;

            q.push({i,j});
            vis[i][j] = 1;
            result2++;
           // cout << i << j<< "\n";

            while(!q.empty()){
                auto cur = q.front(); q.pop();

                for (int k = 0; k < 4; ++k) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx<0 ||nx > n || ny <0 || ny > n) continue;

                    if(vis[nx][ny] != -1) continue;
                    if(board[cur.first][cur.second] == 'B' && board[nx][ny] != 'B') continue;
                    if(board[cur.first][cur.second] != 'B' && board[nx][ny] == 'B') continue;
                    vis[nx][ny] =1 ;
                    q.push({nx,ny});
                   // cout << nx << ny<< " ::\n";

                }
            }

        }
    }

    cout << result << " "<< result2;

}