#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int i = 0;
    for(auto timelog : timelogs){
        int j =0;
        bool flag = true;
        for(int time : timelog){
      
            int date = (startday+j)%7;
            date = date == 0 ? 7 : date;
            
            if(date == 6 || date == 7) {  j++; continue;}
            
            int m = (schedules[i]+10)%100;
            int h = (schedules[i]+10)/100;
            if (m>=60) {
                h++;
                m-= 60;
            }
            
            
       
            
            if(h*100+m < time){
                flag = false;
                break;
            }
            
            j++;
        }
        
        if(flag) answer++;
        i++;
    }
    return answer;
}