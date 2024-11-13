//
// Created by dasoya on 11/13/24.
//


#include "bits/stdc++.h"

using namespace std;

vector<int> failure(string& s){

    vector<int> f(s.size());

    int j = 0;
    for(int i = 1; i < s.size();i++){
        while(j>0 && s[i]!= s[j]) j = f[j-1];
        if(s[i]==s[j]) f[i] = ++j;
    }

    return f;
}

int main(){

    string a,b;
    cin >> a >> b;

    vector<int> f = failure(a);

    int ans = 0;

    int j = 0;
    for(int i =0 ; i <(int)(a.size()); i++){
        while(j>0 && a[i]!=b[j]){j = f[j-1];}
        if(a[i]==b[j]) {
            j++;
            if(j==b.size()) {ans = 1; break;}
        }
    }

    cout << ans;




}