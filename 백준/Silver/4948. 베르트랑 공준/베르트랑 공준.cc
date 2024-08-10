//
// Created by dasoya on 7/30/24.
//

#include "bits/stdc++.h"

using namespace std;


int main(){

    cin.tie(0);
    int n = 1;

    int max = 123456*2;
    vector<bool> prime(123459*2,true) ;

    prime[1] = false;

    // n+1 2n 사이의 소수 갯수 찾기
    for (int i = 2; i*i <= max; ++i) {

        if(!prime[i]) continue;

        for (int j = i*i ; j <= max; j+=i) {
            prime[j] = false;
        }
    }


    while(n!=0){

        cin >> n;

        if(n==0) break;
        
        int cnt = 0;

        for (int i = n+1; i <= 2*n; ++i) {
            if(prime[i]) cnt++;
        }

        cout << cnt <<"\n";

    }
}