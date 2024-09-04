//
// Created by dasoya on 9/2/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    long long a[4002],b[4002],c[4002],d[4002];

    for(int i=0;i<n;i++){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }

  //  sort(a,a+n);
  //  sort(b,b+n);
  //  sort(c,c+n);
   // sort(d,d+n);

    long long ans = 0;

    vector<long long> two1,two2;

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){

            two1.push_back(a[i]+b[j]);
            two2.push_back(c[i]+d[j]);
        }
    }

    sort(two2.begin(),two2.end());

    for(int i = 0; i < two1.size() ; i++) {
        ans += upper_bound(two2.begin(), two2.end(), -two1[i]) - lower_bound(two2.begin(), two2.end(), -two1[i]);
    }
    cout << ans;

}