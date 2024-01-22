//
// Created by dasoya on 1/22/24.
//


#include "iostream"
#include "queue"
#include "stack"

using namespace std;

int dist[100002] ={};


int dx[3] = {0,-1,1};
int dy[3] = {2,1,1};

int main(void){
    int n,k;
    cin >> n >> k;
    int prev[100002] = {};

    cin.tie(0);
    fill(dist,dist+100002,-1);
    fill(prev,prev+100002,0);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    prev[n] = -1;

    while(!q.empty()){

        int cur = q.front(); q.pop();

        if(cur==k){
            cout << dist[cur] << "\n";

            stack<int> s;

            while(cur!=-1){
                s.push(cur);
                cur = prev[cur] ;
            }

            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
            return 0;
        }

        for (int i = 0; i < 3; ++i) {
            int nx = cur*dy[i] + dx[i];

            if(nx<0||nx>100000) continue;
            if(dist[nx] > -1 ) continue;

            q.push(nx);
            dist[nx] = dist[cur] + 1;
            prev[nx] = cur;

        }

    }






}