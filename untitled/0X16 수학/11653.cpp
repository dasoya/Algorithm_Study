//
// Created by dasoya on 7/17/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;
    cin >> n;

    for (int i = 2; i*i <= n; ++i) {
        while(n%i==0){
            n /= i;
            cout << i << "\n";
        }

    }

    if(n!=1)
        cout << n ;


}