//
// Created by dasoya on 9/29/24.
//
#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    int n ;
    cin >> n;

    int h,k;

    vector<pair<int,int>> people;
    multiset<int> team;
//    int curGrade[500001];
//    int curK[500001];

    while(n--){
        cin >> h >> k;
        people.push_back({h,k});

    }

    sort(people.begin(),people.end(),greater<>());

    for(int i = 0; i < people.size(); i++){
        //*
        auto it = team.lower_bound(people[i].second);

        if(it == team.begin()) // k보다 크거나 같은게 존재 하지 않음. it의 Prev가 없음
        {
            team.insert(1);
        }
        else{ // 있으면
         int size = *prev(it);
           team.erase(prev(it));
            team.insert(size+1);
        }
    }

    cout << team.size();

}