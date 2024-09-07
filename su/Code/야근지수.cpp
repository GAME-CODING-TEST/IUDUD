#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // 가장 큰 수를 줄이기 위해 pq 사용
    priority_queue<int> q (works.begin(), works.end());
    
    // n번만 반복
    for(int i = 0; i<n; i++){ 
        // 제일 큰 수가 0이면 반복 할 필요 없음
        if(q.top() == 0) break;
        
        int t = q.top();
        q.pop();
        t--;
        q.push(t);
    }
    
    while(!q.empty()){
        int t = q.top();
        q.pop();
        answer += t*t;   
    }
    
    return answer;
}