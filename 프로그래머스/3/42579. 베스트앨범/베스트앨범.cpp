#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,int> m,n;
    map<string,pair<int,int>> gs;
    
  
    for(int i = 0; i<genres.size();i++){
        m[genres[i]] += plays[i];
        
        if (gs.find(genres[i]) == gs.end()){
            gs[genres[i]] = {-1,-1};
            gs[genres[i]].first = i;
            continue;
        }
        
        //pair<int,int> g = gs[genres[i]];
        
        if(plays[gs[genres[i]].first] < plays[i]){
          
            gs[genres[i]].second = gs[genres[i]].first;
              gs[genres[i]].first = i;
            
        }else if(plays[gs[genres[i]].first] == plays[i]){
            //고유 번호 차이
            if(gs[genres[i]].first < i){
                gs[genres[i]].second = i;
            }else{
                gs[genres[i]].second = gs[genres[i]].first;
               gs[genres[i]].first = i;   
            }
        }else{//첫번째 보다 작다면
     
            if(gs[genres[i]].second == -1)
            {
                gs[genres[i]].second = i;
                continue;
            }
            
            if(plays[gs[genres[i]].second] < plays[i]){
                gs[genres[i]].second = i;
            }else if(plays[gs[genres[i]].second] == plays[i]){
                if(gs[genres[i]].second > i){
                    gs[genres[i]].second = i;
                }
            }
        }
    }
    
    
    priority_queue<pair<int,string>> pq;
    
    for(auto p: m){
        //횟수, 장르
        pq.push({p.second,p.first});
    }
    
    
    while(!pq.empty()){
        
        
        auto p = pq.top(); pq.pop();
        
        string g = p.second;
        cout << g<<" " << p.first <<"\n";
        
        answer.push_back(gs[g].first);
        
        if(gs[g].second != -1){
            answer.push_back(gs[g].second);
        }
    }
    
    return answer;
}