#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> alpha;
    alpha.push(s[0]);
    
    for(int i = 1; i<s.length(); i++){
        if(alpha.empty() || alpha.top() != s[i]){
            alpha.push(s[i]);
        }
        else if(alpha.top() == s[i]){
            alpha.pop();
        }
    }

    return alpha.empty()? 1:0;
}