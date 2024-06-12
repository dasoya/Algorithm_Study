//
// Created by dasoya on 1/14/24.
//



#include "iostream"
#include "bits/stdc++.h"

using namespace std;





int main(void){

    int f,s,g,u,d;
    int dist[1000002] = {};

    cin >> f >> s>> g >> u>> d;

    fill(dist,dist+1000002,-1);

    queue<int> Q;

    Q.push(s);
    dist[s] = 0;

    int dx[2] = {u,-d};
    while(!Q.empty()){
        int x = Q.front();

        Q.pop();

        if (x == g) {
            cout << dist[g];

            for (int i = 1; i < f + 1; ++i) {
                // cout << dist[i] << " ";
            }
            return 0;
        }

        int nxdist = dist[x] +1;

        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];

            if(nx<1 || nx>(f)) continue;
            if(dist[nx]==-1) {

                Q.push(nx);
                dist[nx] = nxdist;

            }
        }

    }

    cout << "use the stairs";
    return 0;



}