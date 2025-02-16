#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
     int idx = 0;
    for(auto c: str){
        
        if(c >= 'a' && c <= 'z'){
        
            str[idx] = toupper(str[idx]);
            
        }else{
              str[idx] = tolower(str[idx]);
        }
        
        idx++;
        
    }
    
    cout << str;
    
    return 0;
}