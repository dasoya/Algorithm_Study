//
// Created by dasoya on 12/28/24.
//


#include "bits/stdc++.h"

using namespace std;

int varr[9],warr[9];
int maxNum = 0;

void solve(int cnt,int n){
    if(cnt == n){
        int sum = 0;

        for(int i = 0 ;i < n;i++){
           // cout << varr[i] <<" ";;
            if(varr[i]<=0)
                sum++;
        }
       // cout << "\n";

        if(maxNum < sum)
            maxNum = sum;
        return;
    }

    if(varr[cnt]<=0){
        solve(cnt+1,n);
        return;
    }

    bool flag = false;

    for(int i = 0 ;i < n;i++){

        if(cnt == i||varr[i] <= 0) continue;
        flag = true;
       // if(cnt != i)
        { varr[i] -= warr[cnt]; varr[cnt] -= warr[i];}
        solve(cnt+1,n);
        //if(cnt != i)
        { varr[i] += warr[cnt]; varr[cnt] += warr[i];}
    }


    if(!flag){
        solve(cnt+1,n);
    }


}

int main(){


    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;

    cin >> n ;

    for(int i = 0; i < n ; i++){
        cin >> varr[i] >> warr[i];
    }

    solve(0,n);

    cout << maxNum;
}