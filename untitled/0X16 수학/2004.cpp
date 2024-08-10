//
// Created by dasoya on 8/9/24.
//

#include "bits/stdc++.h"

using namespace std;
#define MAX 2000000001;

long long func(long long k,int i){
    int cnt = 0;
    while(k){
        cnt += k/i;
        k/=i;
    }

    return cnt;
}


int main(){

    long long m,n;

    cin >> n >> m;
    //nCm = n-1Cm + n-1Cm-1X
    // n! / m! n-m!
    //5의 소인수 갯수
    int cnt = 0;

    int cnt2 = func(n,2) - func(m,2) - func(n-m,2);
    int cnt5 = func(n,5) - func(m,5) - func(n-m,5);


    cout << min(cnt2,cnt5);



}