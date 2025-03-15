#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int i=0,j=0;
    
    bool flag = true;
    for(auto s : goal){
        if(cards1[i]==s){
            i++;
            continue;
        }
         if(cards2[j]==s){
            j++;
            continue;
        }
        
        answer = "No";
        flag = false;
        break;
    }
    
    
    return answer;
}