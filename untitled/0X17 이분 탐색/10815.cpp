//
// Created by dasoya on 8/25/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m;

    cin >> n ;

    int arr_n[500004];//,arr_m[100000005];

    for (int i = 0; i < n; ++i) {
        cin >> arr_n[i];
    }

    cin >> m;

    sort(arr_n,arr_n+n);
    int temp;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        cout << binary_search(arr_n,arr_n+n,temp)<< " ";
    }



}