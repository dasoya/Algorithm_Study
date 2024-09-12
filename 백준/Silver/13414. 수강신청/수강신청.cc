//
// Created by dasoya on 9/12/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int k,l;

    cin >> k >> l;

    unordered_map<string,int> s; // 학번 및 순서.

    for (int i = 0; i < l; ++i) {
        string temp ;
        cin >> temp;
        if(s.find(temp)!=s.end()) {s[temp] = i;}
        else s.insert({temp,i});
    }


    vector<pair<int,string>> v;
    for(auto i:s){
        v.push_back({i.second,i.first});
    }

    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        if(i > v.size()-1) break;
        cout << v[i].second << "\n";

    }

}