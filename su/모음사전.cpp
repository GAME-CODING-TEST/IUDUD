#include <string>
#include <vector>

using namespace std;

int cnt = -1;
string aeiou = "AEIOU";

void dfs(string s, string& target, int& answer){
    cnt++;
    
    if(s==target) {
        answer = cnt;
        return;
    }
    if(s.length() >= 5) return;
    
    for(int i = 0; i<5; i++){
        dfs(s+ aeiou[i], target, answer);
    }
}

int solution(string word) {
    int answer = 0;
    
    dfs("", word, answer);
    return answer;
}