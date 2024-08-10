//
// Created by dasoya on 8/1/24.
//


#include "bits/stdc++.h"

using namespace std;

int arr[104];

//int gcd(int m,int n){
//
//    if(n>m) swap(m,n);
//
//    if(n == 0) return m;
//    m = m%n;
//    return gcd(m,n) ;
//}

//최대 공약수
int gcd(int a, int b){

    if(a==0) {
        return b;
    }

    //작은 수가 a로 가게.
    return gcd(b%a,a);

}


int main(){

    int t;

    cin >> t;

    while(t--){

        int n;
        cin >> n;

        long long sum = 0;
        for(int i=0;i<n;i++) cin >> arr[i];

        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
               sum += gcd(arr[i],arr[j]);
            }
        }

        cout << sum <<"\n";

    }
}