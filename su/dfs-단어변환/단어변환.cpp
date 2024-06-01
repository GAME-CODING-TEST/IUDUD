#include <string>
#include <vector>

using namespace std;

void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt, int& answer){
    for(int i = 0; i<words.size(); i++){
        int count = 0;
        for(int j = 0; j<words[i].length(); j++){
            if(!useCheck[i]&&begin[j]!=words[i][j]) count++;
        }
        if(count==1){
            if(target == words[i] && answer >cnt+1){
                answer = cnt+1;
                return;
            }
            
            useCheck[i] = true;
            dfs(words[i], target, words, useCheck, cnt+1, answer);
            useCheck[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 100;
    vector<bool> useCheck(words.size(), false);
    dfs(begin, target, words, useCheck, 0, answer);
    if(answer == 100) return 0;
    return answer;
}