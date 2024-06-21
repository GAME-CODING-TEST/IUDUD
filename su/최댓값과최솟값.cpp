#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> number;
    
    string tmp;
    // 숫자 저장
    for(int i = 0; i<s.length(); i++){
        if(s[i]!= ' '){
            tmp += s[i];            
        }
        else{
            // stoi = string to int
            number.push_back(stoi(tmp));
            tmp.clear();
        }
    }
    number.push_back(stoi(tmp));
    
    //정렬
    sort(number.begin(), number.end());
    
    // 답 도출
    answer += to_string(number.front()) +" "+to_string(number.back());
    return answer;
}