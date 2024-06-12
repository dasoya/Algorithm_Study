//
// Created by dasoya on 2/1/24.
//

#include "iostream"

using namespace std;


int func(int r, int c, int n){

    if(n==0)
    {
        return 0;
    }

    int half = (1<<n)/2;

    if(r < half && c<half) return func(r,c,n-1);
    if(r < half && c>=half) return func(r,c-half,n-1) + half*half;
    if(r >=half && c<half) return func(r-half,c,n-1) + half*half*2;
    if(r >= half && c>=half) return func(r-half,c-half,n-1) + half*half*3;

}

int main(void){

    int n , r, c;

    cin >> n >> r >> c;

    cout << func(r,c,n);

}