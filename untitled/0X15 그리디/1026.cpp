//
// Created by dasoya on 6/25/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;

    int a[55], b[55];

    cin >> n;
    for(int i =0; i<n;i++ ) cin >> a[i];
    for(int i =0; i<n;i++ ) cin >> b[i];

    sort(a,a+n);
    sort(b,b+n);

    int s =0;

    for (int i = 0; i < n; ++i) {
        s += a[i] * b[n-i-1];
    }

    cout << s;
}