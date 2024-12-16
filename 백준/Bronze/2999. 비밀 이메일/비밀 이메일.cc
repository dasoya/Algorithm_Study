//
// Created by dasoya on 12/16/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    string s;
    cin >> s;

    int n = s.length();
    //n으로 나누어지는 r과 c를 찾고.
    int r,c;
    for(int i = 1; i*i <= n ; i++){
        if(n%i == 0){
            r = i;
            c = n/r;
        }
    }

    string ans = "";
    for(int i = 0; i < r;i++){
        for(int j = 0; j < c; j++){
            ans += s[i+j*r];
        }
    }

    cout << ans;


}