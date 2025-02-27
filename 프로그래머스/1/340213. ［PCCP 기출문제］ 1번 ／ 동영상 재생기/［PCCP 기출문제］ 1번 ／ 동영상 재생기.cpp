#include <string>
#include <vector>
#include "bits/stdc++.h"
#include<string>

using namespace std;

// 첫번째께 적으면 -1 많으면 1 같으면 0
int compareTo(int m, int s, int nm, int ns){
    
    if(m==nm&&s==ns) return 0;
    
    if(m==nm){
        if(s < ns) return -1;
        if(s> ns) return 1;
    }
    
    if(m > nm) return 1;
    else return -1;
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int m = stoi(pos.substr(0,2));
    int s = stoi(pos.substr(3,2));
    
    int stm = stoi(op_start.substr(0,2));
    int sts = stoi(op_start.substr(3,2));
    
    int edm = stoi(op_end.substr(0,2));
    int eds = stoi(op_end.substr(3,2));
    
    for(string cmd : commands){
        
        if(compareTo(m,s,stm,sts)>=0 && compareTo(m,s,edm,eds) <=0){
            m = edm;
            s = eds;
            cout << "op";
        }
        
        if(cmd == "next"){
        
            s += 10;
            if(s>=60) {
                m++;
                s %=60;
            }
            
            int nm =stoi(video_len.substr(0,2));
            int ns = stoi(video_len.substr(3,2));
            
            if(compareTo(m,s,nm,ns) >= 0 ){
                m = nm;
                s = ns;
            }
            
                cout << "nxt";
        }
        else if(cmd == "prev"){
             s -= 10;
            if(s<0) {
                m--;
                s += 60 ;
            }
       
                cout << "prev";
              if(compareTo(m,s,0,0) <= 0 ){
                m = 0;
                s = 0;
            }
        }
        
        if(compareTo(m,s,stm,sts)>=0 && compareTo(m,s,edm,eds) <=0){
            m = edm;
            s = eds;
            cout << "op";
        }
        
    }
    
    string mst = to_string(m);
    string sst = to_string(s);
    if(m<10) mst = "0"+mst;
    if(s<10) sst = "0"+sst;
    
    answer = mst+":"+sst;
    
    return answer;
}