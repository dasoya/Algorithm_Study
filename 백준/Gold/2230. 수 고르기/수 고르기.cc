//
// Created by dasoya on 9/3/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    int a[100005];

    for (int i = 0; i < n; ++i) {

        cin >> a[i];
    }

    int st = 0,en = 1;
    sort(a,a+n);

    int ans = INT32_MAX;
    while(en<n&&st<n){
        if(m>a[en]-a[st]) en++;
        else {
            ans = min(ans,a[en]-a[st]);
            st++;
        }

    }

    cout << ans;
}