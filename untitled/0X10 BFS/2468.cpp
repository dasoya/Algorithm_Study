//
// Created by dasoya on 1/15/24.
//

#include "iostream"
#include "queue"

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){

    int n;
    cin >> n;
    int board[102][102] = {};

    int maxH = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];

            if(board[i][j] >=maxH){
                maxH = board[i][j];

            }

        }
    }
    //cout << maxH;

    int MaxR,maxRain = 0;
    queue<pair<int,int>> Q;
    int result = 0;
    int visit[102][102] = {};


    for (int rain = 0; rain < maxH; ++rain) {
        result = 0;
        for (int i = 0; i <= n; ++i) {
            fill(visit[i],visit[i]+n,0);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if(board[i][j]<=rain) continue;
                if(visit[i][j] == 1) continue;

                Q.push({i,j});
                visit[i][j] = 1;
                result++;

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; ++k) {

                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] <= rain) continue;
                        if(visit[nx][ny] ==1 )continue;

                        Q.push({nx, ny});
                        visit[nx][ny] = 1;

                    }
                }
            }

        }

        if(MaxR<result)
        {
            MaxR = result;
            maxRain = rain;
        }
    }

    cout << MaxR ;//<< " "<<maxRain;

}