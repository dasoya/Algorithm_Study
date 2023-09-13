//
// Created by dasoya on 13.09.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,x;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> x;

    int cnt[1000001], result =0;

    fill(cnt,cnt+1000001,0);

    for(int i : arr){
        if(cnt[x-i]) {
        //cout << i <<" ";
        result++;}
        else cnt[i]++;

    }

    cout << result;

}