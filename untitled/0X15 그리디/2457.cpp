//
// Created by dasoya on 6/26/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    //3월 1 ~ 11월 30일
    //하나는 있어야하고

    int n = 0;

    cin >> n;

    vector<pair<int,int>> flower;

    for (int i = 0; i < n; ++i) {
        int a,b,c,d;
        cin >> a >> b>> c >> d;
        flower.push_back( {a*100+b,c*100+d});
    }

    // 맨 처음엔 3/1일 이전인 걸 선택 해야 함.
    // 그리고 끝나는 시간 이후에 바로 다음거 있으면 그거하고 아니면
    // 겹치더라도 가장 길이가 뒤로 넘어가는 거선택
    // 11.30 넘으면 종료.

    int res  = 0;
    int t = 301;

    while (t<1201) { // 현재 t에 선택할 꽃을 골라!

        int nt = t;

        for (int i = 0; i < n; i++) {
            if (t >= flower[i].first && nt < flower[i].second) { // 301 이전?일 필요는 업고 크지만 않으면 돼
                nt = flower[i].second;
               // cout << nt << "\n";
            }
        }

        if (nt == t) {
            cout << 0;
//            cout << " " << nt;
            return 0;
        }

        res++;
        t = nt;
    }

    cout << res;
    return 0;
}