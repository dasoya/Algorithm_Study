//
// Created by dasoya on 6/23/24.
//
#include "bits/stdc++.h"

using namespace std;


int main(){


    int n;

    cin >> n;

    pair<int,int> arr[100000];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr,arr+n);

    int res = 0;
    int end = 0;

    for (int i = 0; i < n; ++i) {
        //cout <<  arr[i].second<<" " << arr[i].first << "\n";
        if(end <= arr[i].second){
            end = arr[i].first;
            res ++;

           // cout << "--";
        }
    }

    cout <<res;
}