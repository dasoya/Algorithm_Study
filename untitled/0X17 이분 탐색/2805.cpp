//
// Created by dasoya on 8/28/24.
//

#include "bits/stdc++.h"

using namespace std;

int n,m;
int trees[1000005];

bool solve(long long h){

    long long cnt = 0;

    for (int i = 0; i < n; ++i) {
        int temp = trees[i]-h;

        cnt +=  max(temp,0);//0 이하로 들어가면 안됨.
    }

    return m <= cnt;//h가 충분히 낮은 상황. h를 높여야함.
}


int main(){

    cin >> n >> m;


    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
    }

    long long st = 0;
    long long  end = 1000000000;

    while(st<end){

        long long mid = (st+end+1)/2;
        if(solve(mid)){
            st = mid;
        } else end = mid -1 ;
    }

    cout << st;
}