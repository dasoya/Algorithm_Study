#include <string>
#include <vector>

using namespace std;
int ans = 0; 
void solve(int cnt, int sum,vector<int>& numbers, int target){
    
    if(cnt == numbers.size()){
        if(sum == target)
            ans++;
        
        return;
    }
    
    solve(cnt+1, sum-numbers[cnt],numbers,target);
    solve(cnt+1, sum+numbers[cnt],numbers,target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    solve(0,0,numbers,target);
    
    return ans;
}