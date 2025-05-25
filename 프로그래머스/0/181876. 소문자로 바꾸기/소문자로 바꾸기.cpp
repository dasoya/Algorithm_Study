#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(auto c : myString){
        
        if(c >='A' && c<='Z')
        {
            answer += c - 'A' +'a';
        }
        else{
            answer += c;
        }
    }
    
    return answer;
}