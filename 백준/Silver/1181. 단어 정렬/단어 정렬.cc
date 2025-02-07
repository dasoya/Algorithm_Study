//
// Created by dasoya on 2/7/25.
//


#include "bits/stdc++.h"

using namespace std;

bool comp(string &a,string &b){

    if(a.length()!=b.length())
        return a.length() < b.length();

    return a <= b;
}

int main(){

    int n;
    cin >> n;
    string t;


    set<string> s;
    while(n--){
        cin >> t;
        s.insert(t);

    }
    vector<string> v(s.begin(),s.end());
    sort(v.begin(),v.end(),comp);


    for(string i :v){
        cout << i << "\n";
    }
}