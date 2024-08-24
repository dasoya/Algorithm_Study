//
// Created by dasoya on 8/25/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int a,b;

    cin >> a >> b;

    int arr[500005],brr[500005];
    for (int i = 0; i < a; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < b; ++i) {
        cin >> brr[i];
    }

    sort(arr,arr+a);
    sort(brr,brr+b);

    int sum = 0;
    int ans[500005];

    for(int i = 0; i < a; i++){
        if(!binary_search(brr,brr+b,arr[i])) {
            ans[sum++] = arr[i];
        }
    }

    cout << sum << "\n";
    for(int i=0;i<sum;i++) cout << ans[i]<<" ";

}