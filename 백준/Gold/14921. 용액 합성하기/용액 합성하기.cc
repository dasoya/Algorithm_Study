//
// Created by dasoya on 8/31/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){


    int n;
    cin >> n;

    int arr[100005];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i){

        int idx = lower_bound(arr,arr+n,-arr[i]) - arr;

        if(idx!=0&&idx-1 != i && abs(arr[idx-1]+arr[i]) < abs(ans) )
        {
            ans = arr[idx-1]+arr[i];
        }


        if(idx<n&&idx != i && abs(arr[idx]+arr[i]) < abs(ans) )
        {
            ans = arr[idx]+arr[i];
        }

        if(idx+1 <n&&idx +1!= i && abs(arr[idx+1]+arr[i]) < abs(ans) )
        {
            ans = arr[idx+1]+arr[i];
        }
    }

    cout << ans;
}
