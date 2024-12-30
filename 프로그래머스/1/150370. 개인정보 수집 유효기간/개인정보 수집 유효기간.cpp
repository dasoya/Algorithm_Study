#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> terms_map;
    
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int date = stoi(today.substr(8,2));
    
    for(auto term:terms){
      
        //string alpha(term[0],0);
        string date = term.substr(2,term.length()-2);//substr  = pos, n이다. 
        cout <<  date << " ";
        terms_map[term[0]] = std::stoi(date);
    }
    
    int i = 1;
    for(string p : privacies){
        int year1 = stoi(p.substr(0,4));
        int month1 = stoi(p.substr(5,2));
        int date1 = stoi(p.substr(8,2));
       cout << i << " " << year1 <<" " << month1<<" "<<date1<<"\n";
            
        int d_month = ( month1 + terms_map[(char)p[p.length()-1]]) % 12;
        if(d_month == 0) d_month = 12;
        
        int d_year = year1 + (month1 + terms_map[(char)p[p.length()-1]]-1) /12;
        int d_date = date1;
        
        bool flag = false;
        cout << i << " " << d_year <<" " << d_month<<" "<<(char)p[p.length()-1]<<"\n";
        
        if(d_year < year){
            flag = true;
            
        }else if ( d_year == year  ){
            
            if( d_month < month) {
                flag = true;
            }
            else if (d_month == month){
             
                if(d_date <= date)
                    flag = true;
            }
        }
            
        if(flag)
            answer.push_back(i);
        
        i++;
    }
    
    return answer;
}