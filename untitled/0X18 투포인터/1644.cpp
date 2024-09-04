//
// Created by dasoya on 9/3/24.
//


#include "bits/stdc++.h"

using namespace std;
bool check[4000004];

int main(){

    int n;
    cin >> n;

    vector<int> prime;

    //소수를 구할때 i*i가 int 곱하기 int인데 이게 21억을 넘기면 오버 플로우.
    for(long long i=2; i<=n;i++){
        if(!check[i]){
            prime.push_back(i);
            for(long long j = i*i; j<=n; j += i){
                check[j] = true;
            }
        }
    }

    long long ans=0;

    int st=0,en=0;
    long long tot = prime[0];

    while(st<prime.size()){

        while(tot < n) {
            en++;
            if(en>=prime.size()) break;
            tot += prime[en];
        }
        if(en>=prime.size()) break;
        if(tot==n) ans++;
        tot -= prime[st];
        st++;
    }

    cout << ans;
}