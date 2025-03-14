#include <string>
#include <vector>

using namespace std;

int lux = 51,luy=51,rdx=0,rdy = 0;


vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    for(int i = 0; i < wallpaper.size(); i++){
        
        for(int j =0; j < wallpaper[i].length();j++){
            if(wallpaper[i][j]=='#'){
                
                lux = min(lux,j);
                luy = min(luy,i);
                rdx = max(rdx,j+1);
                rdy = max(rdy,i+1);
            }
        }
    }
    
    
    answer = {luy,lux,rdy,rdx};
    return answer;
}