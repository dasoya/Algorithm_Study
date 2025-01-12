#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer,date;
    
    //몇일 째 작업이 완료 되는 지 계산
    for(int i = 0; i < speeds.size();i++){
       date.push_back((100 - progresses[i])/speeds[i]);
       if ((100 - progresses[i])%speeds[i] != 0 )
           date[i]++;
        
    }
    
    int ans = 0;
    
    int pre = date[0];
    
    for(int d =0 ; d< date.size(); d++){
        if(date[d] <= pre)
            ans++;
        else{
            answer.push_back(ans);
            ans = 1;
            //if(d+1 >= date.size()) break;
            pre = date[d];//다음 d로 해야지..
        }
    }
    
     answer.push_back(ans);
    
    return answer;
}