#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> name;
    
    for(int i = 0; i<participant.size(); i++){
        name[participant[i]]++;
    }
    
    for(int i = 0; i<completion.size(); i++){
        name[completion[i]]--;
    }
    
    for(const auto& a : name){
        if(a.second ==1)
            return a.first;
    }
    
    return answer;
}