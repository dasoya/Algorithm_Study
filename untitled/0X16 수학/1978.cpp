//
// Created by dasoya on 7/14/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;

    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; ++i) {

        int temp;

        cin >> temp;
        bool flag = true;
        for (int j = 2; j*j <= temp; ++j) {
            if(temp%j == 0) { flag = false; break;}
        }


        if(temp == 1) flag = false;
        if(flag){  ans++;}


    }

    cout << ans;
}