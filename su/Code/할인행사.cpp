#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> count;
    
    // 맵에 추가
    for(int i=0; i<want.size(); i++){
        count.insert({want[i], number[i]});
    }
    
    for(int i = 0; i<=discount.size()-10; i++){
        map<string, int> newMap;
        for(int j = i; j< i+10; j++){
            newMap[discount[j]]++;
        }
        
        //  모두 할인 받을 수 있는 회원등록 날짜의 일수
        if(count == newMap) answer++;
    }
    
    return answer;
}