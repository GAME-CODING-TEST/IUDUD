#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    set<string> game;
    game.insert(words[0]);
    for(int i = 1; i<words.size(); i++){
        bool endGame = false;
        
        // 글자 수가 1 이하
        if(words[i].length() <2){
            endGame = true;
        }
        // 규칙 위반
        else if(words[i-1][words[i-1].length()-1] != words[i][0]){
            endGame = true;
        }
        // 중복된 단어
        else if(!game.insert(words[i]).second){
            endGame = true;
        }
        
        if(endGame){
            int human = (i+1)%n;
            answer[0] = (human == 0 ? n : human);
            answer[1] = ((i+1)/n);            
            break;
        }
    }

    return answer;
}