//
// Created by dasoya on 11/16/24.
//
#include "bits/stdc++.h"

using namespace std;
vector<int> fa;
int oa[600],ma[600];
int kmpCnt[70];
string a, w, s;

vector<int> failure(string& p){
    vector<int> f((int)p.size());

    int j = 0;
    for(int i = 1; i< (int)p.size();i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    return f;
}

void solve(){


   

    for(int shift = 0; shift < (int)a.size() ; shift++){
        for(int k = 0; k < (int)a.size() ; k++){
            ma[a[k]] = (oa[a[k]]+shift)%(int)a.size();
        }
        int j = 0;
        for(int i =0;i < (int)s.size();i++){
            while(j >0 && oa[s[i]] != ma[w[j]]) j = fa[j-1];
            if(oa[s[i]] == ma[w[j]]) j++;
            if(j==(int)w.size()){
                kmpCnt[shift]++;
                j = fa[j-1];
            }
        }

    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {

        cin >> a >> w >> s;

        vector<int> ans;
        vector<int> ().swap(fa);

        fill(kmpCnt,kmpCnt+70,0);
        for (int i = 0; i < a.size(); i++)
            oa[a[i]] = i;


        fa = failure(w);
        solve();

        for (int i = 0; i < a.size(); i++) {
           // cout << kmpCnt[i];
            if (kmpCnt[i] == 1) {
                ans.push_back(i);
            }
        }

        if(ans.size() == 0) cout << "no solution\n";
        else if(ans.size() == 1)
            cout << "unique: " << ans[0] << '\n';
        else {
            cout << "ambiguous: ";
            for(int k : ans) cout << k << ' ';
            cout << '\n';
        }
    }



}