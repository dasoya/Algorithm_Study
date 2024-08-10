//
// Created by dasoya on 8/9/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;
    int a,b;

    cin >> n >> a >> b;

    int cnt = 1;
    int k = 1;
    while(cnt <= n){

        k*=2;

        int ai ,bi = 0;

        ai = a/k;
        bi= b/k;

        if(a%k==0) ai--;
        if(b%k==0) bi--;

        if(ai==bi) break;

        cnt++;

    }

    cout << cnt;
}