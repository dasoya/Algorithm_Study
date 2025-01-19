#include <string>
#include <vector>

using namespace std;
const int MAX = 20*1000000+10;//노드의 갯수이다.
bool chk[MAX];
int nxt[MAX][10];//현재 노드에서 다음 노드로 갈 수 있는 경우의수 표현 -1이면 못감.
int root = 1;
int unused = 2;//노드다

int c2i(char c){
    return c-'0';
}



void insert(string& s){
    
    int cur = root;
    for(auto c : s){
       if(nxt[cur][c2i(c)] == -1)
           nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    
    chk[cur] = true;
    
}

bool find(string& s){
    int cur = root;
   for(auto c : s){
       if(nxt[cur][c2i(c)]==-1){
           return false;
       }
       cur = nxt[cur][c2i(c)];
   }
    
    return true;
}



bool solution(vector<string> phone_book) {
    bool answer = true;
    
    
    for(int i = 0 ; i<MAX;i++)
         fill(nxt[i],nxt[i]+10,-1);
    
    
    
    for(string s: phone_book){
        if(find(s)) return false;
        
        insert(s);
    }
    
    return answer;
}