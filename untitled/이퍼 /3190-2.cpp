//
// Created by dasoya on 3/24/24.
//


#include "bits/stdc++.h"

using namespace std;
typedef pair<int,int> ci;


int playGame(int n, vector<vector<int>> &board, map<int,char> &cmd){


    //상이 -1임!!! 우 상 좌 하
    int dr[4] = {0,-1,0,1};
    int dc[4] = {1,0,-1,0};


    deque<ci> snake;
    snake.push_front(ci(0,0));
    board[0][0] = 1;

    int t = 0, head = 0;

    while(true){
        t++;

        int nr = snake.front().first + dr[head];
        int nc = snake.front().second + dc[head];

        if(nr < 0 || nr >=n || nc< 0 || nc >=n || board[nr][nc] == 1) break;

        if(board[nr][nc] != 2){
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        snake.push_front(ci(nr,nc));
        board[nr][nc] = 1;

        if(cmd[t] == 'L')
            head = (head + 1)% 4;
        if(cmd[t] == 'D')
            head = (head + 3)% 4;

    }

    return t;
}

int solution(int n, int k, int l, vector<vector<int>> &apple, vector<int> &rotation_t, vector<char> &rotation_d) {


    vector<vector<int>> board(n,vector<int>(n));

    map<int,char> cmd;

    for (int i = 0; i < k; ++i) {

        board[apple[i][0] -1][apple[i][1]-1] = 2;

    }

    for (int i = 0; i < l; ++i) {
        cmd[rotation_t[i]] = rotation_d[i];
    }

    int answer = playGame(n,board,cmd);
    return answer;
}


int main() {
    int n, k, l;
    //입력
    cin >> n >> k;
    vector<vector<int>> apple(k, vector<int>(2));
    for (int i = 0; i < k; i++) //사과 위치
        cin >> apple[i][0] >> apple[i][1];
    cin >> l;
    vector<int> rotation_t(l); //시간
    vector<char> rotation_d(l); //방향
    for (int i = 0; i < l; i++) //회전 정보
        cin >> rotation_t[i] >> rotation_d[i];
    //연산
    int answer = solution(n, k, l, apple, rotation_t, rotation_d);
    //출력0
    cout << answer;
    return 0;
}