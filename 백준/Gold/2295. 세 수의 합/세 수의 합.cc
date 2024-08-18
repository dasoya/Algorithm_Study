//
// Created by dasoya on 8/18/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;

    int u[1005];
    vector<int> two;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            two.push_back(u[i]+u[j]);
        }
    }

    sort(two.begin(),two.end());
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
        if(binary_search(two.begin(),two.end(),u[j]-u[i])) {
            ans = max(u[j], ans);
        }
     }
    }


    cout << ans;




}