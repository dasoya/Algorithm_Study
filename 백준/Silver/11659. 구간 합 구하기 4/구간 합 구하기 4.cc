//
// Created by dasoya on 4/3/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;

    cin >> n >> m;

    int narr[100001];

    narr[0]= 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int temp ;

        cin >> temp;

        sum += temp;
        narr[i] = sum;

    }

    for (int k = 0; k < m; ++k) {

        int i,j = 0;

        cin >> i >> j;

        cout << narr[j] - narr[i-1] << "\n";


    }


}