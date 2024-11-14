//
// Created by dasoya on 11/14/24.
//
#include "bits/stdc++.h"

using namespace std;

vector<int> failure(string& s){

    vector<int> f(s.size());
    int j = 0;

    for(int i = 1; i<(int)s.size();i++){
        while(j>0 && s[i] != s[j]) j = f[j-1];
        if(s[i]==s[j]) f[i] = ++j;
    }

    return f;
}

int main(){

    cin.tie(0);
    string t,p;
    getline(cin,t);
    getline(cin,p);

    vector<int> f = failure(p); //실패 함수는 j에 대한 즉 패턴에 대한 실패 함수를 작성해야한다.
    vector<int> ans;
    int j = 0;
    int cnt = 0;
    for(int i = 0; i < (int)t.size();i++){
        while(j>0 && t[i] != p[j]) { j = f[j-1];  }
        if(t[i] == p[j]) {
            ++j;
        }
        if(j==(int)p.size()){
            j = f[j-1]; // 현재 j가 size이니 인덱스 값인 -1 값으로 업데이트
            cnt++;
            ans.emplace_back(i -p.size()+2 );
        }
    }

    cout << cnt << "\n";

    for(auto i : ans){
        cout << i << " ";
    }

}


