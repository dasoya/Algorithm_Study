#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(int i = 0 ; i < myString.size(); i++)
    {
        if(myString[i] == 'a')
        {
            answer += 'A';
            continue;
        }
        
        if(myString[i] > 'A' && myString[i] <= 'Z'){
              answer += (char)(myString[i]) -'A' +'a';
                continue;
        }
        
        answer += myString[i];
    }
    
    return answer;
}