#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> m;
    
    for(auto c :clothes){
        m[c[1]]++;
    }
    
    for(auto g : m){
       /// cout << g <<" ";
        answer *= g.second +1;
    }
    
    return answer-1;
}