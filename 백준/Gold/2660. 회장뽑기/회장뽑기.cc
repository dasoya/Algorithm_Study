//
// Created by dasoya on 10/5/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<int> adj[54];
int score[54]; // max 값이 들어 가는데
int vis[54];

int main(){

    int n;

    cin >> n;
    int u,v;

    while(true){
        cin >> u >> v;
        if(u==-1&&v==-1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int minScore = 0;
    vector<int> candidate;

    for(int i = 1; i <= n; i++){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){

            int cur = q.front();q.pop();
            for(int nx:adj[cur]){
                if(vis[nx]) continue;
                q.push(nx);
                vis[nx] = vis[cur]+1;
            }
        }

        //다 연결 됐는지 확인. 가장 먼 값-1 저장
        int i_sco = 0;

        for(int j = 1 ; j<=n;j++) {
            if (!vis[j]) {
                i_sco = 0;
                break;
            }

            i_sco = max(i_sco,vis[j]);
        }

        fill(vis,vis+n+1,0);
        score[i]= i_sco;
    }

    minScore = *min_element(score+1,score+1+n);


    for(int i =1;i<=n;i++){
        if(score[i]== minScore)
            candidate.push_back(i);
    }
   cout << minScore-1 <<" "<<candidate.size() <<"\n";

    for(auto i:candidate){
        cout << i<<" ";
    }


}