#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_multiset<string> m(participant.begin(),participant.end());
    
    for(auto c: completion){
        m.erase(m.find(c));
    }
    
    for(auto i : m){
        answer = i;
    }
    
    return answer;
}