//
// Created by dasoya on 7/2/24.
//

#include "bits/stdc++.h"

using namespace std;

bool plug[105];

int main(){

    int n,k;

    cin >> n >> k;

    int arr[105];

    for (int i = 1; i <= k; ++i) {
        cin >> arr[i];
    }

    int res = 0;
    int cnt = 0;

    for(int i = 1; i <= k; i++){

        //이미 꽂혀 있을 때
        if(plug[arr[i]]) {
            continue;
        }

        if(cnt < n){ // 플러그가 다 안 꽂혔을 때

            plug[arr[i]] = true;
            cnt++;
            continue;
        }

        // 매번 새로 확인
        priority_queue<pair<int,int>> q;// 큰 숫자가 먼저
        for (int m = 1; m <= k; ++m) {//1~k 까지 숫자 중 플러그에 꽂힌 숫자 확인

            if(!plug[m]) continue;
            bool flag = false;
            for (int j = i+1; j <= k; ++j) { //지금 숫자 중 다음 나올 숫자. 안 나온다면 k+1로?

                if(m == arr[j]){
                    q.push({j,m});
                    flag = true;
                    break;
                }

            }
           if(!flag) q.push({k+1,m});
        }


            auto target = q.top();
            plug[target.second] = false;
            q.pop();

        plug[arr[i]] = true;
        res++;

    }

    cout << res;

}


