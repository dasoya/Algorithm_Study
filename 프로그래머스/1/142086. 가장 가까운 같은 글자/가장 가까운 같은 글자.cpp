#include <string>
#include <vector>

using namespace std;


vector<int> solution(string s) {
    vector<int> answer;
    vector<int> alpha(26,-1);//마지막으로 나온 인덱스
    
    //fill(alpha.begin(),alpha.end(),-1);
    
    int i = 0;
    for(auto c:s){
        if(alpha[c-'a']==-1){
            answer.push_back(-1);
        }
        else answer.push_back(i-alpha[c-'a']);
        
        alpha[c-'a'] = i;
        i++;
    }
    
    return answer;
}