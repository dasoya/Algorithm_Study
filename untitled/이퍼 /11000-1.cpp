//
// Created by dasoya on 3/24/24.
//

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ci;

int arrayRoom(int n,vector<ci> lec){

    //종료시간을 넣는 pq.
    priority_queue<int,vector<int>,greater<>> pq;

    pq.push(-1);

    for(auto i : lec){

        if(i.first >= pq.top()){
            pq.pop();
        }
        pq.push(i.second);

    }

    return pq.size();
}
int main(void){

    int n;

    cin >> n;

    vector<ci> lec(n,ci(0,0));
    for(int i=0; i<n; i++){
        cin >> lec[i].first >> lec[i].second;
    }

    sort(lec.begin(),lec.end());

    cout << arrayRoom(n,lec) << "\n";
    return 0;
}