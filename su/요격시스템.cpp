#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int idx = 0;
    
    sort(targets.begin(), targets.end());
    
    while(idx<targets.size()){
        //타겟 끝
        int end = targets[idx++][1];
        // 요격 위치 추가
        answer++;
        
        // 시작점이 현재 끝보다 크면 탈출
        while(idx < targets.size()&&targets[idx][0]<end){
            if(targets[idx][1]<end) end = targets[idx][1];
            idx++;
        }
    }
    
    return answer;
}