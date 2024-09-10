//
// Created by dasoya on 9/10/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){

    int n;

    cin >>n;

    unordered_set<string> m;

    for (int i = 0; i < n; ++i) {
        string temp,temp2;
        cin >> temp;
        cin >> temp2;

        if(temp2=="enter")
            m.insert(temp);
        else {
            m.erase(temp);
        }
    }

    vector<string> arr(m.begin(),m.end());

    sort(arr.begin(),arr.end());

    for(int j = arr.size()-1;j>=0; j--){
        cout << arr[j]<<"\n";
    }

}