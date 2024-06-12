//
// Created by dasoya on 1/19/24.
//

#include "iostream"
#include "queue"

using namespace std;

int dist[100002] ={};

int dx[3] = {0,-1,1};
int dy[3] = {2,1,1};

int main(void){
    int n,k;
    cin >> n >> k;

    cin.tie(0);
    fill(dist,dist+100002,-1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);

    while(!q.empty()){

        int cur = q.front(); q.pop();

        if(cur==k){
            cout << dist[cur];
            return 0;
        }
        for (int i = 0; i < 3; ++i) {
            int nx = cur*dy[i] + dx[i];

            if(nx<0||nx>100000) continue;
            if(dist[nx] > -1 ) continue;

            q.push(nx);
            if(i!=0) {
                dist[nx] = dist[cur] + 1;
            }else{
                dist[nx] = dist[cur];
            }

        }

    }




}