#include <string>
#include <vector>

using namespace std;

int K = 10007;
int dp[100001][2]; // 행 - n의 갯수 열 - 마지막이 자유롭지 않을 때와 일때. 

int solution(int n, vector<int> tops) {
    int answer = 0;
    int t = 0;
    
    for(int i : tops){
        if(i==1) t++;
    }
    
    //dp
    //1 테이블 찾기  -> dp 는 n 모형일 때 어쩌구하기 ? top은 나중에 추가? 
    //2 점화식 찾기
    //3 초기값 설정
    
    //결국 두개를 짝찟는방법 아님?
    //마름모가 한개 일때 
    
    //0 -> 1
    //1 -> n*2 + tops.1의 갯수  2*2 + 1
    //2 -> 
    dp[0][0] = 0;  // 2 0 = 
    dp[0][1] = 1; //n이 하나 들때 기본적으로 마름모 한개가 2개 들어갈 수 있움.
    
    for(int i = 1; i <= n; i++){
  
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%K;
        
        if(tops[i-1]==0){
            
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2)%K;
        }else{
            dp[i][1] = (dp[i-1][0]*2 + dp[i-1][1]*3)%K;
        }
      
    }
    
    return (dp[n][0]+dp[n][1])%K;
}