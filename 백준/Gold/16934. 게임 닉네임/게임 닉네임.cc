

#include "bits/stdc++.h"

using namespace std;

const int MX = 100000*10+5;
int chck[MX];
int nxt[MX][26];
int unused = 2;
const int root = 1;

int ctoi(char c){
    return c-'a';
}

void insert(string& s){
    int cur = root;

    string nickname = "";
    bool flag = false;

    for(char c : s){

        if(nxt[cur][ctoi(c)] == -1) {
            nxt[cur][ctoi(c)] = unused++;
            if(!flag) {
                nickname += c;
                cout << nickname << "\n";
                flag = true;
            }
        }
        else  nickname += c;
        cur = nxt[cur][ctoi(c)];
    }

    chck[cur]++;

    if(!flag){
        if(chck[cur]==1)   cout << nickname << "\n";
        else  cout << nickname << chck[cur] << "\n";
    }
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

    cin.tie(0);
    int n;
    cin >> n ;

    string t;

    for(int i = 0; i<MX;i++)
        fill(nxt[i],nxt[i]+26,-1);

    while(n--){
        cin >> t;
        insert(t);
    }



}