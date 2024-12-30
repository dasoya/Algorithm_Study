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
    int todayDate =  year*12*28 +(month-1)*28 + date;
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
        
        int tDate = (d_year)*12*28 +(d_month-1)*28 + d_date;
        if(tDate <=  todayDate)
            answer.push_back(i);
        
        i++;
    }
    
    return answer;
}