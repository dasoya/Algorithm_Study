//
// Created by dasoya on 8/31/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    int n;

    int arr[10005];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);

   // vector<int> two;
    //-4 2 2
    long long ans = 0;
    //2 -5 2 3 -4 7 -4 0 1 -6
    //-6 -5 -4 -4
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int two = arr[i]+arr[j];

            int ub = upper_bound(arr+j+1,arr+n,-two)-arr;
            int lb =  lower_bound(arr+j+1,arr+n,-two)-arr;
            ans += ub -lb;
        }
    }

    cout << ans;



}