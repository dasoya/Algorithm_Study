//
// Created by dasoya on 11/28/24.
//


#include "bits/stdc++.h"

using namespace std;
//vector<int> adj[10004];
int p[10004];
bool pa[10004];

int main(){

    int t;

    cin >> t;

    while(t--){
        int n,k;
        cin >> n;

        int a, b;
        fill(p,p+n+1,-1);
        fill(pa,pa+n+1,false);
        while(--n){
            cin >> a >> b;
            p[b] = a;
            //adj[b].push_back(a);
        }
        cin >> a >> b;

      
        int cur = a;
        while(cur != -1){
            pa[cur] = true;
            cur = p[cur];
        }

        cur = b;
        while(cur != -1){
            if(pa[cur]) break;
            cur = p[cur];
        }

        cout << cur << "\n";
    }
}


