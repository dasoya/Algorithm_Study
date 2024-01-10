//
// Created by dasoya on 1/9/24.
//
#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"

using namespace std;

string board[27];
int visit[27][27]={};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main(){

    int n ;
    cin >> n;
    queue<pair<int,int>> Q;

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    int result =0;
    vector<int> v ;

    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if(board[i][j] == '0') continue;
            if(visit[i][j]==1) continue;

            Q.push({i,j});
            visit[i][j] =1;
            result++;
            count++;

            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for (int k = 0; k < 4; ++k) {

                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(nx<0 || nx >=n || ny <0 || ny >=n) continue;
                    if(board[nx][ny] == '0') continue;
                    if(visit[nx][ny]==1) continue;

                    Q.push({nx,ny});
                    visit[nx][ny] =1;
                    count++;

                }

            }

            v.push_back(count);
            count = 0;
        }
    }


    cout << result << "\n";

    sort(v.begin(),v.end());

    for(auto &a : v){
        cout << a << "\n";
    }


}