//
// Created by dasoya on 2/9/25.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;

    cin >> t;

    while(t--){
        int n,m;

        cin >> n >> m;

        int arr[n],brr[m];

        int tn = n ,tm =m;
        int i = 0;
        while(tn--){
            cin >> arr[i];
            i++;
        }

        i=0;
        while(tm--){
            cin >> brr[i];
            i++;
        }

        //arr  > brr 큰경우가 중요!!
        //b가 a 배열에 들어간다 했을 때 의 위치가 중요하네.

        sort(arr,arr+n);

        int ans = 0;

        for(auto b : brr){

            ans += n - (upper_bound(arr,arr+n,b) - arr);
        }

        cout << ans <<"\n";
    }

}