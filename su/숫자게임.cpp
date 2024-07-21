#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    // 둘의 사이즈 같음
    int n = A.size();
    
    // B가 최초로 이기는 가장 작은 수 구하기
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0;
    
    for(int i = 0; i<n; i++){
        for(int j = idx; j<n; j++){
            if(A[i]<B[j]){
                answer++;
                idx = j+1;
                break;
            }
        }
    }
        
    
    return answer;
}