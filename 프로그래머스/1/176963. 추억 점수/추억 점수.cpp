#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> dict;
    
    for(int i = 0; i< name.size(); i++){
        dict[name[i]] = yearning[i];
    }
    
    for(auto v : photo){
        int ans = 0;
        for(auto who :v){
            ans += dict[who];
        }
        answer.emplace_back(ans);
    }
    return answer;
}