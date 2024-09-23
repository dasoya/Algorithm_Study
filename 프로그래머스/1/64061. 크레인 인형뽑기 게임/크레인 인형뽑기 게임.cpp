//
// Created by dasoya on 9/22/24.
//
#include <string>
#include <vector>
#include "bits/stdc++.h"

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; //사라진 인형의 개수
    stack<int> s[31],baguni;

    for(int i = 0; i< board.size(); i++){
        for(int j = board[i].size()-1; j > -1; j--){
            if(board[j][i] != 0)
             s[i+1].push(board[j][i]);
        }
    }

    for(auto i : moves){

        if(s[i].empty()) continue;


        if(baguni.empty() || baguni.top() != s[i].top()) {
            baguni.push(s[i].top());
        }
        else {
            answer += 2;
            baguni.pop();
        }
        s[i].pop();

    }

    return answer;
}

int main(){

    vector<vector<int>> b= {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};

    cout << solution(b,moves);
}