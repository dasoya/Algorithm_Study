//
// Created by dasoya on 9/20/24.
//

#include "bits/stdc++.h"
typedef long long ll;
using namespace std;

int main(){

    int n,k;
    vector<pair<int,int>> jwerl; //보석의 무게, 가격
    multiset<int> c; //가방

    cin >> n >> k;
    int m,v;
    for(int i=0;i< n;i++){
        cin >> m >> v;
        jwerl.emplace_back(m,v);
    }

    for(int i=0;i<k;i++){
        cin >> m;
        c.insert(m);
    }

   // sort(c.begin(),c.end());
    sort(jwerl.begin(),jwerl.end(),[](const auto& a, const auto& b) {return a.second > b.second;});

    //그리디
    // 행 가방의 무게고, 열 넣는 보석의 종류
    // 가치는 ll -> multi set?
    //     1 2 5   //65 99 23
    // 2  65 99            //가방에 보석을 하나씩 넣으면서 왼쪽과 왼쪽 위를 비교?
    // 10 65 65+99 < 99+23
    // --> 아님 X

    //***가장 가치가 큰 보석은 담을 수 있는 가장 작은 가방에 넣는 것***
    ll ans = 0;

    // 보석을 내림차순으로 보면서 가방을 채워나감.
    // O(n*logk)
    for (int i = 0; i < n; ++i) {
        auto temp = c.lower_bound(jwerl[i].first);
       if( temp != c.end()) {
           ans += jwerl[i].second;
           c.erase(temp);
       }

       if(c.size() == 0 ) break;
    }

    cout << ans;

}