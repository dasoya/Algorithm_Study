//
// Created by dasoya on 8/1/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int i = 1;
    while(true) {

        int l, p, v;
        cin >> l >> p >> v;
        int ans = 0;
        if(l==0&&p==0&&v==0) break;


        ans += v/p * l ;
        ans += min(l,v%p) ;
        cout << "Case " << i << ": "  << ans <<"\n";

        i++;
    }

}