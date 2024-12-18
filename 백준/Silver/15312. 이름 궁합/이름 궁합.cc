//
// Created by dasoya on 12/18/24.
//


#include "bits/stdc++.h"

using namespace std;

int score[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

//3 2 2 3 1 2
// 5 4 5 4 3
//  9 9 9 7
//   8 8 6
//    6 4

int main(){

    string a,b;
    cin >> a >> b;
    queue<int> q,q2;

    for(int i = 0;i < a.length();i++){
        q.push(score[a[i]-'A']);
        q.push(score[b[i]-'A']);
    }
    q.push(-1);

    int cur = q.front(); q.pop();

    while(true){

        int nxt = q.front(); q.pop();
        if(nxt == -1) {
            if(q.size() == 2) break;
            q.push(-1);
            cur = q.front(); q.pop();
            continue;
        }

        q.push((cur+nxt)%10);
        cur = nxt;
    }

    cout << q.front(); q.pop();
    cout << q.front(); q.pop();


    //맨 앞하고 맨 끝을 제외하고 더하기.
    //


}