//
// Created by dasoya on 12/17/24.
//

#include "bits/stdc++.h"

using namespace std;

vector<string> split(string s,const string& t){

    vector<string> arr;
    int pos = 0;

    while(pos < s.length()){
        int nxt = s.find(t,pos);
        if(nxt == -1)
             nxt = s.length();

        arr.push_back(s.substr(pos, nxt-pos));
        pos = nxt+t.size();
    }

    return arr;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    int t;
    getline(cin,s);
    t = stoi(s);
   // cin >> s;
    while(t--){

        getline(cin,s);

        vector<string> arr = split(s," ");
        while(true){
            string temp;
            getline(cin,temp);
            if(temp == "what does the fox say?")
                break;
            vector<string> tarr = split(temp," ");
            auto it = std::find(arr.begin(), arr.end(),tarr[2]);

            while(it != arr.end()){
                arr.erase(it);
                it = std::find(arr.begin(), arr.end(),tarr[2]);
            }
        }

        for(auto k : arr){
            cout << k << " ";
        }
        cout <<"\n";
    }
}