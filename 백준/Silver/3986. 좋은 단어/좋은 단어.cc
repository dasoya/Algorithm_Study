//
// Created by dasoya on 05.10.23.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

     int n, res=0;

     cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        stack<char> st;

        for (int j = 0; j < s.length(); ++j) {

            if(!st.empty()&&st.top()==s[j])
                st.pop();
            else st.push(s[j]);

        }

        if(st.empty()) res++;

    }

    cout << res;
}