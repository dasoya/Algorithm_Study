#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string,int> ranking; 
    
    int i = 0;
    
    for(auto s : players){
        ranking[s] = i++;
    }
    
    for(auto s : callings){
    
       string temp =  players[ranking[s]-1];
       players[ranking[s]] = temp;
       players[ranking[s]-1] = s;
        
       ranking[s]--;
       ranking[temp]++;
    }
    

    return players;
}