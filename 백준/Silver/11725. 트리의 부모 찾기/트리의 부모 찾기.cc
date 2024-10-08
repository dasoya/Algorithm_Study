//
// Created by dasoya on 10/8/24.
//

#include "bits/stdc++.h"
using namespace std;
int p[100001];
vector<int> adj[100001];
int main(){

    int n,x,y,vsize;
    cin >> n;
    vsize = n;

    while(n--){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()){

        int cur = q.front(); q.pop();

        for(int nxt: adj[cur]){
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }

    for(int i = 2; i <= vsize; i++){
        cout << p[i] << "\n";
    }

}