#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string as = to_string(a);
    string bs = to_string(b);
    
    if(as+bs > bs+as)
        return stoi(as+bs);
    else return stoi(bs+as);
}