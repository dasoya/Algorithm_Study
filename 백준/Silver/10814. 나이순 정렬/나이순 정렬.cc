//
// Created by dasoya on 2/15/25.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    int n ;

    cin >> n ;
    vector<tuple<int,int,string>> v;

    int idx = 0;
    while(n--){
        int k;
        string temp;

        cin >> k >> temp;
        v.emplace_back(k,idx++,temp);//이거 차이
    }

    sort(v.begin(),v.end());

    for(auto i : v){
        int k;
        int idx;
        string temp;

        tie(k,idx,temp) = i;

        cout << k <<" " << temp <<"\n";

    }

}

//,[](tuple<int,string> a,tuple<int,string> b){
//        int k,k2;
//        string temp,temp2;
//
//        tie(k,temp) = a;
//        tie(k2,temp2) = b;
//
//        if (k != k2)
//            return k < k2;
//
//        cout << temp << temp2;
//        return true;
//
//    }