//
// Created by dasoya on 11/20/24.
//
#include "bits/stdc++.h"

using namespace std;
//범위 한번더 확인
const int MAX = 10000*10+5;
const int root = 1;
int unused = 2;
int nxt[MAX][11];
bool check[MAX];

int ctoi(char c){
    return c-'0';
}

bool insert(string& s){

    int cur = root;

    for(int i = 0; i < (int)s.length() ; i++){
        char c = s[i];
        //nxt는 현재 c가 들어갈 공간.
        if(nxt[cur][ctoi(c)] == -1) {
            nxt[cur][ctoi(c)] = unused++;
            //체크가 이제 나는데 새 노드가 생기지 않고 일치 하는 노드가 있는 경우.
        }else if(i== s.size()-1){
            return false;
        }

        cur = nxt[cur][ctoi(c)];

        if(check[cur]){
            return false;
        }

    }

    check[cur] = true;
    return true;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int t,n;
    cin >> t;

    while(t--){

        //테스트케이스 마다 관련 변수 초기화!!!!!!
        fill(check, check + MAX, 0);
        cin >> n;
        string s;
        for(int i = 0; i < MAX; i++)
           fill(nxt[i],nxt[i]+10, -1);

        unused = root +1;
        
        bool ans = true;
        while(n--){
            cin >> s;
            if(!insert(s)) ans = false;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";

    }
}

