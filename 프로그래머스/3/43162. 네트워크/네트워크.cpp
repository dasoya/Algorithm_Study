#include <string>
#include <vector>

using namespace std;

bool visited[201];

void dfs(int cur,int n, vector<vector<int>>& computers){
    
    
    for(int i = 0 ; i < n ; i++){
        
        if(visited[i] || computers[cur][i] == 0) continue;
        visited[i] = true;
        dfs(i,n,computers);
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(visited[i]) continue;
        visited[i]= true;
        dfs(i,n,computers);
        answer++;
    }
    
    
    return answer;
}