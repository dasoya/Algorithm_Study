#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int n = friends.size();
    
    map<string, int> dict; // friends의 번호 
    
    vector<vector<int>> table(n,vector<int>(n,0)); //gitf 주고받은 이력
    vector<int> score(n,0);
    
    vector<int> total(n,0); // 받은 선물 
    
    
    for(int i=0; i < n ; i++){
        dict[friends[i]] = i; 
    }
    
    for(auto s : gifts){
        stringstream ss(s);
        
        string a,b;
        ss >> a >> b;
        
        table[dict[a]][dict[b]]++;
        score[dict[a]]++;
        score[dict[b]]--;
    }
    
    for(int i =0;i < n; i ++){
        for(int j =0; j < n ; j++){
            
            if(i==j) continue;
            
            if(table[i][j] > table[j][i])
            {
                total[i]++;
            }
            else if(table[i][j] == table[j][i]){
                if(score[i] > score[j]){
                    total[i]++;
                }
              
            }
        }
    }
    
    answer = *max_element(total.begin(),total.end());
    
    return answer;
}