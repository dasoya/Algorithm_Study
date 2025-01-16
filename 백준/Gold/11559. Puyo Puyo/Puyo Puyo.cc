//
// Created by dasoya on 1/16/25.
//

#include "bits/stdc++.h"

using namespace std;

string board[12];

//같은건 bfs같은 걸로 퍼트리고 지움.
//지운 다음에 다시 내림
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n = 12, m = 6;
int curVisited[12][6];

int bfs(pair<int,int> c){
    int visited[12][6];
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>> q;

    visited[c.first][c.second] = 1;
    curVisited[c.first][c.second] = true;
    q.push(c);
    int maxD = 1;

    int cnt = 0;
    while(!q.empty()){
        auto[cx,cy] = q.front(); q.pop();

        //더 이상 전진할 수 없음을 어떻게 알아? bfs! 거리를 구해주니까!
        //추적해서 지우려면?
        for(int i = 0 ; i< 4; i++ ){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx  < 0  || nx >= n || ny <0 || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if(board[cx][cy] != board[nx][ny]) continue;
            visited[nx][ny] = visited[cx][cy] + 1;
            curVisited[nx][ny] = true;
            maxD++;
            q.push({nx,ny});
        }
    }

   // cout <<"\n" << maxD << "maxD / " << board[c.first][c.second] <<"\n";
    if(maxD >= 4){
        cnt++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(visited[i][j]>0){
                    board[i][j] = '.';
                }
            }
        }
    }

    return cnt;
};

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int ans = 0;

    for(int i = 0 ; i < 12 ; i++){
        cin >> board[i];
    }

    while(true) {

        int cnt = 0; // 터진 그룹의 수
        memset(curVisited,0,sizeof(curVisited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!curVisited[i][j] &&board[i][j] != '.'){
                    cnt += bfs({i,j});
                }

            }
        }

        if(cnt == 0) break;
        ans++;

        //제거하고 내려주는 연산
        for (int j = 0; j < m; j++) {
            queue<int> q;
            for (int i = n-1 ; i >=0; i--) {
                if(board[i][j] == '.'){
                    q.push(i);
                }
                else{
                    if(q.empty()) continue;
                    int cur = q.front(); q.pop();
                    board[cur][j] = board[i][j];
                    board[i][j] = '.';
                    q.push(i);
                }

            }
        }

    }

    cout << ans;

}