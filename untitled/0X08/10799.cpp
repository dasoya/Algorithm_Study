#include<bits/stdc++.h>

using namespace std;

int main(){

    int result = 0;
    string s;
    cin >> s;

    stack<char> st;
    int laser_cnt = 0;

    for (int i = 0; i < s.length() ; ++i) {
        if(s[i]=='(') {
            st.push(s[i]);

        }

        if(s[i]==')'&& s[i-1] == '(')
        {
            st.pop();
            result += st.size();
            continue;
        }

        if(s[i]==')')
        {
            st.pop();
            result ++;


        }

    }

    cout << result;
}
