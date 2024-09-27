#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAXV = 1000002;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    vector<int> in_degree(MAXV,0);
    vector<int> out_degree(MAXV,0);
    
    vector<vector<int>> adj_list(MAXV);
    
    //리스트에 정점 채우기
    for(const auto& e : edges){
        int st = e[0];
        int end = e[1];
        
        out_degree[st]++;
        in_degree[end]++;
  
        
        adj_list[st].push_back(end);
        
    }
    
    //그린 정점 찾기
    int point = -1;
    for(int i = 1; i < adj_list.size(); i++){
        if(in_degree[i] == 0 && out_degree[i] >= 2){
            point = i;
            cout << "point";
            break;
        }
    }
    
    if(point == -1) return answer;

    
    int line = 0, eight = 0;
    
    //지우기
    for(int i = 0; i < adj_list[point].size(); i++){
        int p = adj_list[point][i];
        in_degree[p]--;
        if(in_degree[p] == 0 && out_degree[p]==0)
            line++;
    }
    
    for(int i = 1; i < MAXV; i++){ 
        //line
        if(in_degree[i] == 1 && out_degree[i] == 0) line++;
        if(in_degree[i] == 2 && out_degree[i] == 2) eight++; 
        
    
    }
    
    answer[0]= point;
    answer[1] = adj_list[point].size() - line - eight;
    answer[2]= line;
    answer[3] = eight;
    
    return answer;
}