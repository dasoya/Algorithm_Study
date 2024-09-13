//
// Created by dasoya on 9/13/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;

    cin >> n >> m;

    unordered_map<string,string> list;

    string pw,site;
    while(n--){
        cin >> site >> pw;
        list.insert({site,pw});

    }

    while(m--){
        cin >> site;
        cout << list[site] <<"\n";
    }

}