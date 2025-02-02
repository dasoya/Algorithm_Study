//
// Created by dasoya on 2/2/25.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    int n,w,l;

    cin >> n >> w >> l;

    int arr[1001];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int t = 0;
    int cur_l=0;

    int st = 0,end = 0;
    queue<pair<int,int>> q;


    while(true){
        t++;
        //먼저 내림
        if(!q.empty()) {
            auto cur = q.front();

            if (t - cur.second >= w) {
                q.pop();
                cur_l -= arr[st];
                st++;
                if (st >= n) {
                    break;
                }

            }
        }

        //최대 하중이 넘지 않아야하고, 최대 길이도 넘지 않아야함.
        if(st-end <= w && cur_l + arr[end] <= l){
            q.push({end,t});
            cur_l += arr[end];
            end++;

        }
    }


    cout << t;

}