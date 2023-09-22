//
// Created by dasoya on 19.09.23.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    list<char> editor = {};

    string s;
    cin >> s;

    for(auto i: s){
        editor.push_back(i);
    }

    auto t = editor.end();
    int m;
    cin >> m;
    char cmd;
    while(m--){
        cin >> cmd;

        switch (cmd) {
            case 'L' :
               if(t!=editor.begin()) t--;
                break;
            case 'D' :
                if(t!=editor.end()) t++;
                break;
            case 'B' :
               // cout << *t <<" ";

                if(t!=editor.begin()) t = editor.erase(--t); //erase 후 t를 반환 받아야함.
                break;
            case 'P' :
                char temp;
                cin >> temp;
                editor.insert(t,temp);
//if(editor.end() != t) t++;
                break;
        }
    // cout << *t <<" ";

    }

    for(auto i: editor){
        cout << i ;
    }

}