//
// Created by dasoya on 26.09.23.
//

#include "bits/stdc++.h"
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int temp;
    cin >> n;

    queue<int> q ;

    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;

        if(!cmd.compare("push")){
                cin >> temp;
                q.push(temp);
        continue;
        }

        if(!cmd.compare("pop")){
                if(q.empty()) cout << "-1" <<"\n";
                else{ cout << q.front() <<"\n";
                q.pop();}
            continue;
        }

        if(!cmd.compare("front")){
                if(q.empty()) cout << "-1"<<"\n";
                else
                    cout << q.front()<<"\n";
                continue;
        }
        if(!cmd.compare("back")){
                if(q.empty()) cout << "-1"<<"\n";
                else cout << q.back()<<"\n";
                    continue;
        }
        if(!cmd.compare("size")){
                cout << q.size() <<"\n";
                        continue;
                }
        if(!cmd.compare("empty")){
                if(q.empty()) cout << "1"<<"\n";
                else cout << "0"<<"\n";
                            continue;
        }

        }
}

