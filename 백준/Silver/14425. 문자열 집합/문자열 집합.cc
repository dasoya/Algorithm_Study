//
// Created by dasoya on 11/19/24.
//

#include "bits/stdc++.h"

using namespace std;

const int MX = 10000*500+5;
bool chck[MX];
int nxt[MX][26];
int unused = 2;
const int root = 1;


int ctoi(char c){
    return c-'a';
}

void insert(string& s){
    int cur = root;

    for(char c : s){
        if(nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }

    chck[cur] = 1;
}

bool fetch(string& s){
    int cur = root;
    for(char c : s){
        if(nxt[cur][ctoi(c)] == -1)
            return 0;
        cur = nxt[cur][ctoi(c)];
    }

    return chck[cur];
}

int main(){

    int n ,m,ans =0 ;
    cin >> n >> m;

    string t;

    for(int i = 0; i<MX;i++)
        fill(nxt[i],nxt[i]+26,-1);

    while(n--){
        cin >> t;
        insert(t);
    }

    while(m--){
        cin >> t;
        if(fetch(t)) ans++;
    }

    cout << ans;

}