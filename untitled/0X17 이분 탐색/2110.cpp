//
// Created by dasoya on 8/31/24.
//


#include "bits/stdc++.h"
#define ll long long
using namespace std;

int n,c;
int x[200003];

bool solve(int m){ //m의 가장 인접한 공유기의 거리일 때 공유기의 갯수는 c보다 작나 크나? --> 최소 m미터의 간격으로 공유기를 설치할 때 설치할 수 있는 최대 공유기의 갯수

    int cnt = 0;

    int idx = 0;

    while(idx != n){

        idx = lower_bound(x+idx,x+n,x[idx]+m) -x;
        cnt++;
    }

    return c  <= cnt;
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x,x+n);

    int st = 0;
    int end = 1e9+1;


    while(st<end){
        int mid = (st+end+1)/2;

        if(solve(mid)) st= mid;
        else end = mid-1;
    }
    //다음 공유기를 설치할 가장 먼 index가 무엇인가?

    cout << st;

}