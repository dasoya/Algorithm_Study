//
// Created by dasoya on 04.10.23.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin >> s;
    stack<char> st;
    int result = 0;

    for (int i = 0; i < s.length(); ++i) {

        if(s[i]=='(' || s[i] == '[') {
            st.push(s[i]);
            continue;
        }
        else if(!st.empty())
        {
            if( (s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[')) {
                if (i - 1 >= 0 && s[i - 1] == '(' || s[i - 1] == '[') {
                    int temp;
                    s[i] == ')' ? temp = 2 : temp = 3;

                    st.pop();

                    stack<char> ts;
                    while (!st.empty()) {
                        if (st.top() == '(')
                            temp *= 2;
                        if (st.top() == '[')
                            temp *= 3;

                        ts.push(st.top());
                        st.pop();

                    }

                    result += temp;
                    while (!ts.empty()) {
                        st.push(ts.top());
                        ts.pop();
                    }
                }
                else st.pop();
                continue;
            }


        }

        result = 0;
        break;

    }

    if(st.empty()) cout << result;
    else cout << 0;


}