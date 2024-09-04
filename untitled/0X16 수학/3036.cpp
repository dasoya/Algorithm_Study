//
// Created by dasoya on 8/13/24.
//

#include "bits/stdc++.h"

using namespace std;


int gcd(int a, int b){


    if(a==0) return b;

    //if(a>b) swap(,ㅠ)
    return gcd(b%a,a);
}

int main(){

    int n;

    cin >> n;

    int first,k;
    cin >> first;
    for(int i = 1; i < n;i++){

        cin >> k;
        int dividor = gcd(first,k);
        cout << first/dividor<<"/"<< k/dividor<<"\n";

    }

}