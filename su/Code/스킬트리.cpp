#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> learn;
    for(int i = 0; i<skill.length(); i++){
        learn[skill[i]] = i+1;
    }
    
    for(int i = 0; i<skill_trees.size(); i++){
        int cur = 1;
        bool check = true;
        string skt = skill_trees[i];
        for(int j = 0; j<skt.length(); j++){            
            if(learn[skt[j]] > cur){
                check = false;
                break;
            }
            // 선행 스킬을 배웠으면 다음으로 넘어가기
            else if(learn[skt[j]] == cur){
                cur++;
            }
            
        }
        if(check) answer++;
    }
    
    return answer;
}