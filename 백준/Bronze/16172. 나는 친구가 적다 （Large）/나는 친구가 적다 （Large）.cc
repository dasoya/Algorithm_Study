//
// Created by dasoya on 11/15/24.
//

#include "bits/stdc++.h"

using namespace std;

int main(){

        string s = "",k;

        cin >> s >> k;

        string s_deleted;

        for(int i = 0 ; i < s.length();i++){
            if(s[i]>='0'&&s[i]<='9') continue;
            s_deleted += s[i];
        }

        if(strstr(s_deleted.c_str(),k.c_str())){
            cout << 1;
        }else{
            cout << 0;
        }
}