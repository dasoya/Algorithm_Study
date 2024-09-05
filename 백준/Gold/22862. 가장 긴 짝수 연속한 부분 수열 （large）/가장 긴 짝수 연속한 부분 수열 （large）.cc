//
// Created by dasoya on 9/5/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){

    int n,k;

    cin >> n >> k;
    int arr[1000005];

    for(int i=0; i<n;i++) cin >> arr[i];

    int st =0, en =0;
    int usedk = 0; // 사용한 k의 개수

    int ans = 0,tot = 0;
    while(st < n){

        while(en < n){

           if(arr[en]%2!=0) {

               if(usedk+1 <= k) usedk++;
               else break;

           }
           else tot++; // 짝수니까 길이 증가.
           en++;

        }

        ans = max(ans,tot);
        if(arr[st]%2!=0) usedk--; // 홀수 빼는 거면 k 감소
        else tot--; // 짝수면 답 길이 감소
        st++;

    }
    //짝수거나, 홀순데 k 남아있으면 나아감.

    cout << ans;
}