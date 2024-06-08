#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<int> _stack;
    
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            _stack.push(0);
        }
        else if(s[i] == ')'){
            if(_stack.empty()){
                return false;
            }
            _stack.pop();
        }
    }
    
    if(_stack.empty()) return true;
    return false;
}