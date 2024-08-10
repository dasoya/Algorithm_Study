//
// Created by dasoya on 7/21/24.
//


#include "bits/stdc++.h"

using namespace std;


int gcd(int m,int n){

    if(n>m) swap(m,n);

    if(n == 0) return m;
    m = m%n;
    return gcd(m,n) ;
}



int lcm(int m,int n){

    return m / gcd(m,n) * n;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int m,n,x,y;

        cin >> m >> n >> x >> y;

        int res = -1;

        int max = lcm(m,n);

        if(x==m) x = 0; // 다 채워진 얘는 초기화를 직접 해주고.
        if(y==n) y = 0;

        for (int i = 1; i <= max; ++i) {
            if(i%m==x) {
                for (int j = i; j <= max; j += m) {

                    if (j % n == y) {
                        res = j;
                        break;
                    }
                }
                break;
            }
        }

        cout << res <<"\n";


    }
}