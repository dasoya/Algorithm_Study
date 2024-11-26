

//
// Created by dasoya on 11/26/24.
//

#include "bits/stdc++.h"

using namespace std;
int n ;
const char mo[3] = {' ','+','-'};
vector<string> ans;
bool visited[15];

void back(int idx,deque<int> m){

    if(idx == n){

            string a = "1";
            int pre = 1;
            int sum = 0;
            for (int i = 2; i <= n; i++) {

                if(m.front()!=0) {
                    sum += pre;
                    if(m.front()== 1) {
                        pre = i;
                    }
                    if(m.front()==2) {
                        pre = -i;
                    }


                }else{
                    int pm = 1;
                    if(pre<0)  pm = -1;
                    pre = pre*10 +i*pm;
                   // a +=  to_string(i) ;
                }
                a += mo[m.front()] + to_string(i) ;

                m.pop_front();
            }

            sum += pre;

            if(sum==0)
                cout << a <<"\n";
            //ans.push_back(a);
            return;
    }

    for (int i = 0; i < 3; ++i) {
        m.push_back(i);
        back(idx+1,m);
        m.pop_back();

    }
}

int main(){

    int t;
    cin >> t;

    while(t--){

        cin >> n;

        deque<int> m;

        back(1,m);

//        sort(ans.begin(),ans.end());
//        for(auto s : ans){
//            cout << s <<"\n";
//        }
        cout << "\n";
       // ans.clear();

    }

}
