//
// Created by dasoya on 8/11/24.
//


#include "bits/stdc++.h"

using namespace std;
int arr[1005];

int main(){

    int a,b;
    cin >> a >> b;

    // 1 2 3 4
    // 1 2 2 3 3 3
    //

    int k =0,ans = 0;
    for (int i = 1; i < 1001; i+=k) {

        k++;
        for (int j = i; j < k+i; ++j) {
            arr[j] = k;
            if(j >=a && j <=b ) ans += arr[i];
        }


    }

    cout << ans;
    // for (int i = a; i <= b; ++i) {
    //  ans += arr[i];
    // }
}