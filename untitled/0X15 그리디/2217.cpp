//
// Created by dasoya on 6/24/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;

    cin >> n;

    int arr[100001];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);


    int res = 0;

    for (int i = 1; i <= n; ++i) {

        res = max(res,arr[n-i]*i);
    }

    cout << res;


}