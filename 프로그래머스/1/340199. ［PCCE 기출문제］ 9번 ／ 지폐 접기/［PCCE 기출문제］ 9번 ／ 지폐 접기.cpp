#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int a = bill[0];
    int b = bill[1];
    
    if(b>a)
        swap(b,a);
    
    int l = wallet[0];
    int s = wallet[1];
    
    if(s>l)
        swap(s,l);
    
    while(true){
        
        if(l>=a && s >=b){
            break;
        }
       
        answer++;
        a/=2;
        if(b>a)
            swap(b,a);
        
        
    }
    
    return answer;
}