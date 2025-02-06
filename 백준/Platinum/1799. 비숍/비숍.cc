//
// Created by dasoya on 2/6/25.
//


#include "bits/stdc++.h"

using namespace std;

vector<pair<int,int>> board[2][20];

int n;

int visited[2][1000];//대각선 방문 여부 (n-1)*2+1
//int visit2[1000];

int ans[2];

void back(int cnt,int idx,int color){ // cnt는 현재 비숍을 넣은 갯수.


    if(idx>= 2*n){
        ans[color] = max(cnt,ans[color]);
        return;
    }

    for (auto v : board[color][idx]) {

        int i = v.first;
        int j = v.second;

        if(visited[color][i+j]) continue;

        visited[color][i+j] = true;
        back(cnt+1,idx+1,color);
        visited[color][i+j] = false;
    }

    back(cnt,idx+1,color);

}


int main(){

    cin.tie(0);

    cin >> n;

    int d;
    for (int i = 0; i < n; ++i) {
        for(int j = 0 ; j < n;j++){
            cin >> d;

            if(d){
                board[(i+j)%2][i-j+n-1].push_back({i,j});
            }
        }
    }

    back(0,0,0);
    back(0,0,1);

    cout << ans[0]+ans[1];



}
