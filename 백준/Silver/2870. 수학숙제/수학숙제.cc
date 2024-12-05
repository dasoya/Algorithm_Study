//
// Created by dasoya on 12/5/24.
//


#include "bits/stdc++.h"

using namespace std;

string removeZero(string& s){

    string ans;
    int pos = 0;
    for(char c : s){
        if(c != '0') break;
        pos++;
    }

    ans = s.substr(pos,s.size()-pos);
    if(ans.empty()) ans = "0";

    return ans;
}

bool comp(string& a, string& b) {

    if(a.length() != b.length()) return a.length() < b.length();

    return a<b;
}


int main(){

    int n; string s;
    cin >> n;

    vector<string> ans;

    while(n--){
        cin >> s;
        string digit = "";
        for(char c : s){
            if(c>='a'&&c<='z'){
                if(!digit.empty()){

                    ///000 01 002
                    ans.push_back(removeZero(digit));
                    digit = "";
                }
                continue;}
            digit += c;
        }

        if(!digit.empty()){ ans.push_back(removeZero(digit)); digit = "";}
    }

    sort(ans.begin(),ans.end(),comp);

    for(string i : ans){
        cout << i <<"\n";
    }
}