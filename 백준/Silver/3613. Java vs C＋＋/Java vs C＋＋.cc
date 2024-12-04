//
// Created by dasoya on 12/4/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<string> split(string& s,const string& sep){

    vector<string> ans;
    int pos = 0;
    while(pos < s.size()){
        int nxt = s.find(sep,pos);
        if(nxt == -1){
            nxt = s.size();
        }
        //if(nxt - pos > 0)
        ans.push_back(s.substr(pos,nxt-pos));
        pos = nxt + sep.size();
    }

    return ans;
}

int main(){

    string s;

    cin >> s;

    bool isJava = false;

    string ans ="";

    for(auto c: s){
        //c를 찾는거야.
        if(c>='A' && c<='Z'){
            isJava = true;
            ans += '_';
            ans += (char)('a'+(c - 'A'));

        }
        else{
            ans += c;
        }
    }

    //_도 있고 대문자도 있는 경우 Error!
    if(s.find("_") != -1 && isJava || s[0] == '_' || s[s.size()-1] == '_')
        cout << "Error!";
    else if(isJava) {
        char c = s[0];
        if(c>='A' && c<='Z')
        {
            cout << "Error!";
            return 0;
        }
        cout << ans;
    }
    else{
        vector<string> arr = split(s,"_");
        ans = "";
        for(string t: arr){
            if(t.empty()) {
                cout << "Error!";
                return 0;
            }
            t[0] = (char)((t[0] -'a')+'A');
            ans += t;//+'/';
        }
        ans[0] = (char)('a'+(ans[0]- 'A'));

        cout << ans;
    }


}


//_dask
//daskD