//
// Created by dasoya on 10/3/24.
//

#include "bits/stdc++.h"

using namespace std;


int main(){

    int n;

    cin >> n;

    int date,number;

    priority_queue<int> candidate;
    vector<vector<int>> cn_byDeadline(200002);


    for(int i =0; i<n; i++){
        cin >> date >> number;
        cn_byDeadline[date].emplace_back(number);
    }

    int ans = 0;
    for(int i = 200001; i > 0 ; i--){
       for(int cd : cn_byDeadline[i]){
           candidate.push(cd);
       }

       if(!candidate.empty()) {
           ans += candidate.top();
           candidate.pop();
       }

    }

    cout << ans ;

}