#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> me;
    map<int,int> brother;
    
    // 모든 토핑 한 곳에 저장
    for(int i = 0; i<topping.size(); i++){
        me[topping[i]]++;
    }
    
    for(int i = 0; i<topping.size(); i++){
        // 내꺼 줄이고 동생꺼 늘리기
        me[topping[i]]--;
        brother[topping[i]]++;
        
        // 해당 토핑은 없다
        if(me[topping[i]] == 0){
            me.erase(topping[i]);
        }
        if(me.size() == brother.size()){
            answer++;
        }
    }
    
    return answer;
}