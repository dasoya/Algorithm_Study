#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> tr) {
    int t = 0;
    
    int cweight = 0;
    int cnt = 0;
    int p1 = 0; // 다리를 건너는 맨 앞 트럭 표시
    int p2 = 0; // 대기 트럭 첫번째 표시
    
    queue<int> truck_time;
    
    while(true){
        
        t++;
        
        if(!truck_time.empty()&&t - truck_time.front() >= bridge_length){
            cnt--;
            cweight -= tr[p1];
            p1++;
            truck_time.pop();
            
            if(p1 == tr.size()) break;
        }
        
        if(p2< tr.size() && cweight + tr[p2]  <= weight && cnt +1 <= bridge_length ){
            cweight += tr[p2];
            cnt++;
            p2++;
            truck_time.push(t);   
        }
        
    
    }
    
    return t;
}