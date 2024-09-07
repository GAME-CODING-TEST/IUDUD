#include <string>
#include <vector>

using namespace std;

void dfs(int cur, int& answer){
    if(cur == 0) return;
    
    if(cur %10 > 5 || (cur%10 == 5 &&(cur%100)/10 >=5)){
        answer += 10-cur%10;
        cur += 10;
    }
    else answer += cur %10;
    if(cur/10 > 0) dfs(cur/10, answer);
}

int solution(int storey) {
    int answer = 0;
    dfs(storey, answer);
    return answer;
}