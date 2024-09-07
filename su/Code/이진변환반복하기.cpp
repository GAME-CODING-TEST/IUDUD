#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
        
    while(s.length() > 1){
        string tmp = "";
        for(int i = 0; i<s.length(); i++){
            // 0의 갯수
            if(s[i] == '0'){                
                answer[1]++;
            }
            else{
                tmp+=s[i];
            }
        }
        
        // 이진수 변화후 기존 문자열에 덮어쓰기
        s = bitset<32>(tmp.length()).to_string();
        
        // 이진수로 변환한 문자열에서 앞의 불필요한 '0'을 제거
        s = s.substr(s.find('1'));

        answer[0]++;
    }
    
    return answer;
}