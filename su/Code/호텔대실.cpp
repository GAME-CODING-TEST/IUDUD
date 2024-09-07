#include <string>
#include <vector>

using namespace std;

int stoiTime(string s){
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> room(1440, 0);
    
    for(auto time : book_time){
        int start = stoiTime(time[0]);
        int end = stoiTime(time[1])+10;
        if(end >1440) end = 1439;
        
        for(int i = start; i<end; i++){
            room[i]++;
            answer = max(room[i], answer);
        }
    }
    
    return answer;
}
