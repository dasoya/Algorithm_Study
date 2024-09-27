//
// Created by dasoya on 9/27/24.
//
#include "bits/stdc++.h"

using namespace std;

int n,c;
int x[200003];
bool installByD(long long d){


    int cnt = 0;

    int idx = 0;

    while(idx != n){

        idx = lower_bound(x+idx,x+n,x[idx]+d) -x;
        cnt++;
    }

    return c <= cnt;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i =0; i<n;i++){
        int temp;
        cin >> temp;
        x[i] = temp;
    }

    sort(x,x+n);

    //거리
    long long st = 0;
    long long end = 1e9+1;
    long long mid;

    while(end > st){

        mid = (st+end+1)/2;

        if(installByD(mid)){
            st = mid;
        } else end = mid-1;
    }

    cout << st;
}


