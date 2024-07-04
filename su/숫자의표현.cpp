#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 자기 자신
    int answer = 1;
    
    // 0은 자연수가 아니기 때문에
    for(int i = 1; i<n; i++){
        int sum = 0;
        int start = i;
        while(sum < n){
            sum += start;
            start++;
        }
        
        if(sum == n) answer++;        
    }
    
    return answer;
}