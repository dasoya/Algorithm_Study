//
// Created by dasoya on 2/7/25.
//


#include "bits/stdc++.h"

using namespace std;

int main(){


    int n;

    // string arr[1000001];
    //long long array[1000001];
    vector<long long> v;


    //a b c d
    //d c b a
    cin >> n;
    string temp,temp2 = "";
    for(int i = 0; i < n; i++){
        cin >> temp;
        temp2 = "";
        for(long long j = (long long)temp.length()-1; j >=0;j--){
            temp2 += temp[j];
        }

        v.emplace_back(stoll(temp2));
    }

    std::sort(v.begin(), v.end());

    for(long long i : v){
        cout << i << "\n";
    }


}