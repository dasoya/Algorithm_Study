#include<vector>
#include "bits/stdc++.h"

using namespace std;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int visited[101][101];

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
   // cout << visited[n][m];
    
    while(!q.empty()){
        
        auto cur = q.front(); q.pop();
        
        for(int i = 0; i < 4 ; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx > n) continue;
            if(ny < 0 || ny > m) continue;
            
            if(maps[nx][ny] == 0 || visited[nx][ny]!= 0) continue;
            
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            q.push({nx,ny});
            //cout << nx <<" "<<ny <<"\n";
        }
    }
        
    
    if(visited[n][m]== 0){
        return -1;
    }
    else{
        return visited[n][m];
    }
}