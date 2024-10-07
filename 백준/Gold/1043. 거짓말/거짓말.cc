//
// Created by dasoya on 10/7/24.
//

#include "bits/stdc++.h"

using namespace std;

int n,m,tn;
bool truth[51];
vector<int> adj[51]; // 파티 연결된 거 표시
vector<int> party[51];

void bfs(){

    bool vis[51];
    fill(vis,vis+51,false);

    for (int i = 1; i <= n; ++i) {

        if(!truth[i] || vis[i]) continue;

        queue<int> q;
        q.push(i);
        vis[i] = true;

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nxt:adj[cur]){

                if(vis[nxt]) continue;

                truth[nxt] = true;
                q.push(nxt);
                vis[nxt] = true;
            }
        }

    }

}

int main(){

    cin >> n >> m >> tn;

    int idx,amount;
    while(tn--){
        cin >> idx;
        truth[idx] = true;
    }

    for(int p = 0; p < m;p++){

        cin >> amount;

        while(amount--){
            cin >> idx;
            party[p].push_back(idx);
        }

        //그래프 연결
        for(int i = 0; i < party[p].size();i++)
            for(int j = i+1; j < party[p].size();j++){

                int p1 = party[p][i];
                int p2 = party[p][j];
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);

            }

    }

    //진실 아는 사람 체크
    bfs();

    //파티 배열 다시 돌려서 몇개의 파티에서 과장된말 할 수 있는 지 확인

    int ans = 0;

    for(int i =0 ; i< m;i++){

        bool flag = true;
        for(auto p:party[i]){

            if(truth[p]){flag = false; break;}
        }

        if(flag) ans++;

    }

    cout << ans;
}





//vector<int> combi(party[p].size(), 0);
//        combi[0] = 1;
//        combi[0] = 1;
//
//        do{
//
//        }
//        while(!prev_permutation(combi.begin(),combi.end()));