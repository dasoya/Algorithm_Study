//
// Created by dasoya on 9/13/24.
//

#include "bits/stdc++.h"
//9375
using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        unordered_map<string, int> list;

        while(n--) {
            string a, b;
            cin >> a >> b; // 이름 종류
            list[b]++;
        }

        int ans  = 1;
        for(auto l : list){
          ans *= l.second+1; //안 입는 경우도 고려해서 곱함
        }

        cout << ans-1 << "\n"; // 알몸인경우 제외

    }


}