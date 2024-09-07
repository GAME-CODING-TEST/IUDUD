#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if('a'<=s[0]&&s[0]<='z') s[0]-= ('a' - 'A');
    
    for(int i = 0; i<s.length(); i++){
        if('A'<=s[i+1]&&s[i+1]<='Z') s[i+1] += ('a' - 'A');
        if(s[i] == ' '){
            if('a'<=s[i+1]&&s[i+1]<='z') s[i+1] -= ('a' - 'A');
        }
    }
    return s;
}