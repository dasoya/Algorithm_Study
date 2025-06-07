#include <string>
#include <vector>
#include "bits/stdc++.h"

using namespace std;

vector<int> graph[51];
int visited[51];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
     queue<int> q;
    
    int targetIndex = -1;
    words.push_back(begin);
    
    for(int i = 0 ; i < words.size() ; i++)
    {
        if(words[i]==target) 
        {
            targetIndex = i;
        }
        
        for(int j = 0 ; j < words.size() ; j++){
            
            if(i==j) continue;
            
            int diff = 0;
            
            for(int k = 0; k < words[0].size();k++){
                if(words[i][k]!=words[j][k])
                    diff++;
                
                if(diff > 1){
                    break;
                }
            }
            
            if(diff <= 1){
                graph[i].push_back(j);
                if(words[i]==begin){
                    q.push(j);
                    visited[i] = 10000;
                    visited[j] = 1;
                    cout << words[j] <<" ";
                }
            }
        }
        
    }
    
    
    while(!q.empty()){
        
        int cur = q.front(); q.pop();
    
        
        for(int i = 0 ; i < graph[cur].size();i++){
            
            int next = graph[cur][i];
            
            if(visited[next]) continue;
      
            visited[next] = visited[cur]+1;
                   cout << visited[next] <<":"<< words[next] <<" ";
            q.push(next);
            
        }
        
    }
    
    
    if(targetIndex==-1||visited[targetIndex]==0){
        return 0;
    }
    

    return visited[targetIndex];
}