//
// Created by dasoya on 7/2/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end());

    int x = -1000000001, y = -1000000001 ;

    long long res = 0;

    for (int i = 0; i < n; ++i) {

        if(v[i].first > y){

            res += y-x;
            x = v[i].first;
            y = v[i].second;
            continue;
        }


        if(v[i].second > y)
        y = v[i].second;

    }

    res += y-x;

    cout << res;


}