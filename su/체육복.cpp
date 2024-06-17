#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    // 아이들이 모두 체육복을 가지고 있다고 가정
    vector<int> training(n, 1);

    // 체육복이 없는 아이
    for(int i = 0; i<lost.size(); i++){
        training[lost[i]-1]--;
    }
    // 여벌이 있는 아이
    for(int i = 0; i<reserve.size(); i++){
        training[reserve[i]-1]++;
    }
    
    for(int i = 0; i<n; i++){
        // 현재 학생이 나눠줄 수 있는 상태일 때
        if(training[i] == 2){
            if(i>0 && training[i-1] == 0){
                training[i-1]++;
                training[i]--;
            }
            else if( i< n-1 && training[i+1] == 0){
                training[i+1]++;
                training[i]--;
            }                
        }
    }
    for(int i = 0; i<n; i++){
        if(training[i] == 0) answer--;
    }
    return answer;
}