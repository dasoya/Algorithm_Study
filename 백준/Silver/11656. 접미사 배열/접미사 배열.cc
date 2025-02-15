//
// Created by dasoya on 2/15/25.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

    string input;

    cin >> input;

    string k = "";

    vector<string> s;
    for(int i = input.length()-1;i >= 0 ; i--){

        k = input[i] + k;
        s.emplace_back(k);

    }

    sort(s.begin(),s.end());

    for(string i : s){
        cout << i <<"\n";
    }

}