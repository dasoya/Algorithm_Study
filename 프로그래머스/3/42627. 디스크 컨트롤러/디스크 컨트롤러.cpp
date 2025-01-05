#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) 
            return a.first > b.first; // Min-heap based on the first value (작업 시간 오름차순)
        return a.second > b.second;   // Tie-breaking by the second value (요청 시간 오름차순)
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
  
    sort(jobs.begin(),jobs.end());
    //이건 틀림. 왜냐면.. 현재 요청 시간에서 가장 적은 시간을 골라야하는데...
    //그러면 작업이 끝날때마다 업데이트를 해줘야할듯. 
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq; //작업 시간, 요청 시간, 작업 번호
    
    int jIdx = 0, time = 0;
    
    for(auto job :jobs){//s I
        
        if(job[0]==0){
            pq.push({job[1],job[0]}); //작업 시간 오름차순, 요청시간 오름차순
            jIdx++;
        }
    }
    
    while(jIdx < jobs.size() || !pq.empty()){
        
        if(pq.empty()){
            time++;
            
        }else{
            auto cur = pq.top(); pq.pop();
            time += cur.first; // time은 작업 완료 시간.
            answer += time - cur.second; // 반환시간 합산.
            cout << time << " "<< cur.second <<" |";
        }
        
        //늘어난 타임에 맞게 요청된 작업 넣기
        for(int i = jIdx ; i<jobs.size();i++  ){//s I

            if(jobs[i][0]<=time){
                pq.push({jobs[i][1],jobs[i][0]}); //작업 시간 오름차순, 요청시간 오름차순
                jIdx++;
            }
        }
    }
    
    cout << answer;
    
    return answer / jobs.size();
}