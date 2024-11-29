//
// Created by dasoya on 11/28/24.
//

//
// Created by dasoya on 11/28/24.
//


#include "bits/stdc++.h"

using namespace std;
vector<int> adj[50004];
int p[50004];
bool pa[50004];

void dfs(int cur){

    for(int nxt : adj[cur]){

        if(nxt == p[cur])continue;
        p[nxt] = cur;
        dfs(nxt);
    }

    return;
}

int main(){

        int n,k;
        cin >> n;

        int a, b;
        fill(p,p+n+1,-1);

        for(int i =0;i<n-1;i++){
            cin >> a >> b;
            adj[b].push_back(a);
            adj[a].push_back(b);
        }

        dfs(1);
        cin >> k;

        while(k--) {
            fill(pa,pa+n+1,false);
            cin >> a >> b;

            int cur = a;
            while (cur != -1) {
                pa[cur] = true;
                cur = p[cur];
            }

            cur = b;
            while (cur != -1) {
                if (pa[cur]) break;
                cur = p[cur];
            }

            cout << cur << "\n";
        }

}


