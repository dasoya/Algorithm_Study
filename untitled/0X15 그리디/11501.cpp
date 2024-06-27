//
// Created by dasoya on 6/27/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;

    cin >> t;

    int data[1000000];

    while(t--){

        int n;
        cin >> n;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
           cin >> data[i];
        }

        int mv = data[n-1]; //처음 시작하면 Max값 역순으로 진행하념 맥스 값 필요 없?
        //범위의 문제
        //지금 검사해야하는건 현재부터 뒤까지임
        //뒤부터 검사하면 이미 검사해야하는 것을 전부 검사하고 왔음.

        for (int i = n-2; i >= 0; --i) {

           if(mv<data[i]) mv = data[i];
           else ans += mv -data[i];
        }

        cout << ans << "\n";

        //데이터에서 내 날짜이후로 최댓값으로 팜.

    }




}