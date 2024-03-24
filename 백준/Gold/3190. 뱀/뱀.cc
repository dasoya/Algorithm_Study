//
// Created by dasoya on 3/15/24.
//

#include "bits/stdc++.h"

using namespace std;

int n;
int k;



pair<int,int> Head[4] = {{1,0},{0,1},{-1,0},{0,-1}};

queue<pair<int,char>> dir;

int main(){
    int arr[101][101];
    cin >> n;
    cin >> k;

    int x,y;

    for (int i = 0; i < k; ++i) {
        //x가 행이고, y가 열임
        cin >> x >> y;
        //첫번째 인덱스를 x로가져가면, 열임.
        arr[y-1][x-1] = 1;
    }

    int l;
    cin >> l;

    int a;
    char b;
    for (int i = 0; i < l; ++i) {
        cin >> a >> b;
        dir.push({a,b});
    }

    int t = 0;
    int dIndex = 0;
    deque<pair<int,int>> snake;
    snake.push_back({0,0});
    arr[0][0] = -1;

    while(true){
        t++;

        int nx,ny = 0;

        nx = snake.front().first + Head[dIndex].first;
        ny = snake.front().second + Head[dIndex].second;

        if(nx<0 || ny<0 || nx >=n || ny >= n) break;
        if(arr[nx][ny] == -1) break;

        //사과가 아니면 움직임
        if(arr[nx][ny] == 1){


        } else{
            auto t = snake.back();
            arr[t.first][t.second] = 0;
            snake.pop_back();

        }

        snake.push_front({nx,ny});
        arr[nx][ny]= -1;


        if(dir.front().first == t){
            if(dir.front().second == 'D')
            {
                dIndex++;
                dIndex %= 4;
            }
            if(dir.front().second == 'L')
            {
                dIndex--;
                if(dIndex<0) dIndex = 3;
            }

            dir.pop();

        }
    }


    cout << t;
}