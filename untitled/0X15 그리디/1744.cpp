//
// Created by dasoya on 6/30/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int plus=0;
    int minus=0;

    cin >> n;

    int arr[51];
    int marr[51]; // 0이 포함

    for (int i = 0; (i) < n; ++(i)) {
        int temp;
        cin >> temp;

        if(temp>0){ arr[plus] = temp; plus++;}
        else { marr[minus] = temp; minus++;}

    }

    sort(marr,marr+minus);
    sort(arr,arr+plus);
    //-가 홀수야. 그럼 가장 작은 -는 0이랑 합쳐짐
    //0이 있고
    //-가 홀수
    //0이 없고

    int res = 0;
    for (int i = 0; (i) < minus ; i+=2) {

        if(i+1 >= minus) res+= marr[i];
        else{

            res+= marr[i] * marr[i+1];
        }

    }


    for (int i = plus-1; (i) >= 0 ; i-=2) {

        if(i-1 < 0) res+= arr[i];
        else{

            if(arr[i] ==1 || arr[i-1] ==1 ) res+= arr[i] + arr[i-1];
            else res+= arr[i] * arr[i-1];
        }

    }


    cout << res;

}