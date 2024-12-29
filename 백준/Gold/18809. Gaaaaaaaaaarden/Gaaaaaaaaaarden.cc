//
// Created by dasoya on 12/29/24.
//
//
// Created by dasoya on 12/29/24.
//


#include "bits/stdc++.h"

using namespace std;
int arr[50][50];
int mat[50][50]; // 0 호수 1 배양액 못 뿌리는 땅 2 뿌리는 땅 3 그린 4 레드 11꽃
int maxFlower = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,g,r;
int visited[50][50];
vector<pair<int,int>> initLands;
const int GREEN = 3;
const int RED = 4;
const int FLOWER = 100;
//시간 초과 + 구현 실수가 있음
//백트래킹을 순열로? subset?
//
int getFlowerCnt(){

    int cnt = 0;
    pair<int,int> state[50][50];

    //bfs로 꽃피는지 계산? t일때의 상황을 알아야함.
    queue<tuple<int,int>> q;
    for(int i = 0; i<n;i++)
        for(int j = 0; j<m;j++){
            arr[i][j] = mat[i][j];

            if(arr[i][j]==3){
                q.push({i,j});
                state[i][j] = {0,3};
            }
            else if(arr[i][j]==4){
                q.push({i,j});
                state[i][j] = {0,4};
            }
        }

    while(!q.empty()){
        int x, y;
        tie(x,y) = q.front(); q.pop();
        if(state[x][y].second==FLOWER) continue;
        for(int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 ||nx >= n || ny < 0 || ny >= m) continue;
            if(mat[nx][ny] == 0) continue;
            if(state[nx][ny].second == 0){
                state[nx][ny].second = state[x][y].second;
                state[nx][ny].first = state[x][y].first+1;
                q.push({nx,ny});
            }
            else if(state[nx][ny].first == state[x][y].first+1 && state[nx][ny].second == GREEN &&state[x][y].second == RED ) {
                cnt++;
                state[nx][ny].second = FLOWER;
                state[nx][ny].first = state[x][y].first+1  ;
                continue;
            }
            else if(state[nx][ny].first == state[x][y].first+1 && state[nx][ny].second == RED &&state[x][y].second == GREEN){
                cnt++;
                state[nx][ny].second = FLOWER;
                state[nx][ny].first = state[x][y].first+1  ;
                continue;
            }
        }
    }

    return cnt;
}

//배양액을 뿌리는 경우의 수 (백트래킹보다 조합이 훠월씬 빠름.)  -> 꽃을 피우는 경우의 수 (bfs?)


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> g >> r;

    for(int i = 0 ;i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 2){
                initLands.push_back({i,j});
            }
        }

    int iCnt = initLands.size();
    vector<int> v(iCnt,0);

    fill(v.end()-r-g,v.end()-r,1);
    fill(v.end()-r,v.end(),2);

    do{
        for(int i = 0; i< initLands.size();i++){
            if(v[i]==1){
                mat[initLands[i].first][initLands[i].second] = 3;
            }else if(v[i]==2){
                mat[initLands[i].first][initLands[i].second] = 4;
            }else{
                mat[initLands[i].first][initLands[i].second] = 2;
            }
        }

        maxFlower = max(getFlowerCnt(),maxFlower);
    }while(std::next_permutation(v.begin(), v.end()));

    //solve(0,g,r);

    cout << maxFlower;

}

//2 2 1 1
//3 1
//1 4

//5 5 2 2
//0 0 0 0 1
//0 0 0 0 3
//1 1 4 1 1
//4 1 3 0 1
//0 1 0 0 1