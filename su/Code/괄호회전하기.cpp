#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.length();
    
    for(int i = 0; i<size; i++){
        int start = i;
        stack<char> bracket;
        bool flag = false;
        for(int j = 0; j<size; j++){
            if(start>=size) start = 0;
            char c = s[start];
            
            if(c == '['){
                bracket.push(c);
            }
            else if(c == '{'){
                bracket.push(c);
            }
            else if(c == '('){
                bracket.push(c);
            }
            else if(c == ']'){
                if(bracket.top() != '['){
                    flag = true;
                }else{
                    bracket.pop();
                }
            }
            else if(c == '}'){
                if(bracket.top() != '{'){
                    flag = true;
                }
                else{
                    bracket.pop();
                }
            }
            else if(c == ')'){
                if(bracket.top() != '('){
                    flag = true;
                }
                else{
                    bracket.pop();
                }
            }
            
            if(flag) {
                break;
            }
        start++;
        }
        if(!flag && bracket.empty()) answer++;        
    }
    
    return answer;
}