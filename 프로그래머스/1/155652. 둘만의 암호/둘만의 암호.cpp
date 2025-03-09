#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(auto c : s){
        
        int sk = 0;
        for(int i = 1 ; i <= index+sk;  i++)
        {
            int k = (c-'a'+i)%26;
            
            char t = 'a'+k;
            cout << t;
            if(skip.find(t) != string::npos){
                sk++;
                cout << "-";
                continue;
            }
            
        
        }
    
        answer += 'a' + (c+index+sk-'a')%26;
    }
    return answer;
}