//
// Created by dasoya on 8/8/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;

    cin >> t;

    while(t--){

        long long x, y;
        cin >> x >> y;

        long long  ans = 0;
        //앞에선 k가 1,2,3,... ,4 3,2 뒤에선 1
        //y-x = n

        //n 3 4 5
        //a 3 3 4
        //  2+2
        // 1 1 2 2 3 3     //1 2 3
        // 1 2 4 6 9 12    //2 6 12
        //
        // 1 2 3
        //    2
        bool flag = false;
        //     if(flag) i++;
        //            flag = !flag;
        int total = 1;
//         n = ()/2;
//
//        for(int i = 1; total < n; ){
//            ans+=2;
//            if(total+i >= n){
//               if((total+i-n) * 2 <= i) ans--;
//               break;
//            }
//            total += i;
//        }

        cout << floor(sqrt(y-x)*2-1e-9)<< "\n";

    }
}