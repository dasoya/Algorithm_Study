//
// Created by dasoya on 9/25/24.
//

#include "bits/stdc++.h"

using namespace std;
string s;

int lefteatHam(int start,int end){

    for(int i = start; i < end; i++){
        if(s[i]== 'H'){
            s[i] = 'E';
           // cout << s<<"\n";
            return 1;
        }
    }

    return 0;
}

int righteatHam(int start,int end){

    for(int i = start; i > end; i--){
        if(s[i]== 'H'){
            s[i] = 'E';
         //   cout << s<<"\n";
            return 1;
        }
    }

    return 0;
}
int main(){

    int n,k;
    int ans = 0;

    cin >> n >> k;

    cin >> s;
    // HH P H PP HH PP H PPPHPHPHP
    // 먹을 수 있는 햄버거의 갯수
    // - 남이 먹은 햄버거의 갯수

    for(int i = 0; i < s.length(); i++){
        if(s[i]!='P') continue;

        if(lefteatHam(i-k,i)){
            ans++;
            continue;
        }

        else if(lefteatHam(i+1,i+k+1)){
            ans++;
            continue;
        }

    }


    cout << ans;

}