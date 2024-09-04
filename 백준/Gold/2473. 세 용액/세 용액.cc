//
// Created by dasoya on 8/31/24.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main(){

    int n;
    ll arr[5005];

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);
    ll ans1=1e9+1;
    ll ans2=1e9+1;
    ll ans3=1e9+1;

    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j){

            int idx = lower_bound(arr,arr+n,-arr[i]-arr[j])-arr;

            for (int k = -2; k < 3; ++k) {

                if(idx+k == i ||idx+k==j) continue;
                if(idx+k <0 || idx+k >=n) continue;

                if(abs(ans1+ans2+ans3) > abs(arr[idx+k]+arr[i]+arr[j]))
                    tie(ans1,ans2,ans3) = {arr[i],arr[j],arr[idx+k]};

            }


        }

    if(ans1 > ans2) swap(ans1,ans2);
    if(ans2 > ans3) swap(ans2,ans3);
    if(ans1 > ans2) swap(ans1,ans2);
    cout << ans1 << " " << ans2 << " " << ans3;
}