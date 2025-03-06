#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int pl = p.size();
    
    //if(t.size()< p.size()) return 
    
    for(int i = 0; i < t.size()-pl+1 ; i++){
        
       // cout << t.substr(i,pl) <<" ";
        
        //정수 비교가 안됨 너무 커서
        //p가 같거나 크면됨
        // for(int j = 0; j < pl; j++)
        // {
        //     if(stoi(t[i+j]) <)
        // }
        if(t.substr(i,pl) <= p)
            answer++;
    }
    
    return answer;
}