//
// Created by dasoya on 8/28/24.
//


#include "bits/stdc++.h"

using namespace std;

int m,n;
int L[1000005];
bool solve(long long mid){

    long long cnt = 0;
    for (int i = 0; i < n ; ++i) {
        cnt += L[i]/mid;
    }

    return cnt >= m;
}

int main(){


    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        cin >> L[i];
    }

    sort(L,L+n);

    long long st = 0;
    long long end = 1000000000;
    while(st<end){
        long long mid = (st+end+1)/2;

        if(solve(mid)) st = mid;
        else end=mid-1;
    }

    cout << st;
   // cout<< 0;

}