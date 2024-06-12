//
// Created by dasoya on 3/13/24.
//

#include "bits/stdc++.h"

using namespace std;

int func(int n, vector<pair<int,int>> v){

    priority_queue<int,vector<int>,greater<>> pq; //숫자가 작은 것부터 반환.

    pq.push(-1);

    for(int i = 0; i < n; ++i) {

        if(pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }

    return pq.size();
}

int main(){

    int n;
    int s,t;

    cin >> n;

    int result = 0;
    vector<pair<int,int>> v(n,pair<int,int>(0,0));

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());
    cout << func(n,v);

}