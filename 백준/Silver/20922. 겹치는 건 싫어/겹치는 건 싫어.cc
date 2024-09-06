//
// Created by dasoya on 9/6/24.
//
#include "bits/stdc++.h"

using namespace std;


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int  n, k;

    cin >> n >> k;

    int arr[200005];
    for (int i = 0; i<n;i++) {cin >> arr[i];}

    int st = 0,en =0;
    int ans = 0,tot=0;
   // vector<bool> check(100003,false);
    vector<int> krr(100003,0);
    while(st<n){

        while(en<n){

            if(krr[arr[en]]+1<=k){
                krr[arr[en]]++;
                tot++;
                en++;
            }
            else break;
        }

        ans = max(ans,tot);
        krr[arr[st]]--;
        tot--;
        st++;

    }


    cout << ans;


}