//
// Created by dasoya on 9/11/24.
//


#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m;

    cin >> n >> m;

    unordered_map<string,int> dogam;
    vector<string> v;

    string temp;
    for(int i=1;i<=n;i++){

        cin >> temp ;
        dogam.insert({temp,i});
        v.push_back(temp);
    }

    while(m--){

        cin >> temp;

        if('A'<=temp[0]&&'Z'>=temp[0]){
            cout << dogam[temp]<<"\n";
        }
        else cout << v[stoi(temp)-1] << "\n";

    }



}