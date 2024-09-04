//
// Created by dasoya on 8/17/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

   vector<int> arr,uniq;
   int x[1000005];

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        x[i] = temp;
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; ++i) {

        if(i==0 || arr[i-1]!=arr[i]){
            uniq.push_back(arr[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        //uarr[1];
        cout << lower_bound(uniq.begin(),uniq.end(),x[i]) - uniq.begin() <<" ";
    }

}