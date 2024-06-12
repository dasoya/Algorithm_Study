//
// Created by dasoya on 3/10/24.
//
#include <bits/stdc++.h>

using namespace std;

int main(){

    stack<char> ans2;
    queue<char> ans;
    string input;

    cin >> input;

    sort(input.begin(),input.end());


    char joker = 'a';
    for (int i = 0; i < input.length(); i= i+2) {
        if(input[i]!=input[i+1]) {
            if(input.length()%2 == 0 ) {
                cout << "I'm Sorry Hansoo"; return 0;
            }

            if(joker != 'a'){ cout << "I'm Sorry Hansoo"; return 0;}

            joker = input[i];
            i++;

        }
        if(i>=input.length()) break;

        if(input[i]==input[i+1]) {
            ans.push(input[i]);
            ans2.push(input[i + 1]);
        }else {  cout << "I'm Sorry Hansoo"; return 0;}
    }

    while(!ans.empty()){
        cout << ans.front(); ans.pop();
    }

    if(joker != 'a') cout << joker;

    while(!ans2.empty()){
        cout << ans2.top(); ans2.pop();
    }



}