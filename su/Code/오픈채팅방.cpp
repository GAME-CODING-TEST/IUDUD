#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

vector<string> split(const string& input, char delimeter){
    vector<string> result;
    int pos = 0;
    
    string token = "";
    istringstream tokenStream(input);
    while(getline(tokenStream, token, delimeter)){
        result.push_back(token);
    }
    return result;
    
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    // UID로 닉네임 관리
    map<string, string> uid;
    
    // enter 0, leave 1 관리
    queue<pair<int, string>> talk;
    
    for(int i = 0; i<record.size(); i++){
        vector<string> text = split(record[i], ' ');
        
        if(text[0] == "Enter"){
            uid[text[1]] = text[2];
            talk.push({0, text[1]});
        }
        else if(text[0] == "Leave"){
            talk.push({1, text[1]});
        }
        else if(text[0] == "Change"){
            uid[text[1]] = text[2];
        }
    }
    
    while(!talk.empty()){
        pair<int, string> talking = talk.front();
        if(talking.first == 0){
            answer.push_back(uid[talking.second] + "님이 들어왔습니다.");
        }
        else {
            answer.push_back(uid[talking.second] + "님이 나갔습니다.");
        }
        talk.pop();
    }
    
    return answer;
}