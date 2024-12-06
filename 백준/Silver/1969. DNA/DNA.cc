//
// Created by dasoya on 12/6/24.
//
#include "bits/stdc++.h"

using namespace std;

int cnt[4];
char order[4] = {'A','C','G','T'};

int main(){
    int n,m;
    cin >> n >> m;

    map<char,int> dict;
    dict['A'] = 0;
    dict['T'] = 0;

    vector<string> arr;

    while(n--){
        string s;
        cin >> s;
        arr.push_back(s);
    }

    string dna ="";
    int ans = 0;

    for(int i = 0; i< m;i++){ //어떤 알파벳
        dict.clear();

        for(string t : arr){
            dict[t[i]]++;
        }

        int max_cnt = 0;
        char alpha ;
        for(auto d : dict){
            if(d.second > max_cnt) {
                alpha = d.first;
                max_cnt = d.second;
            }
        }

        dna +=  alpha;

        for(auto d : dict){
            if(d.first != alpha){
                ans += d.second;
            }
        }

    }

    cout << dna << "\n";
    cout << ans;





}