#include <string>
#include <vector>

using namespace std;

bool isDevided(int num, vector<int>& A, vector<int>& B){
    for(int i = 0; i<A.size(); i++){
        // 나눠지면 false 리턴
        if(B[i]%num ==0) return false;
        // 나눠지지 않으면 false 리턴
        if(A[i]%num !=0) return false;
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    for(int i = arrayA[0]; i>1; i--){
        if(isDevided(i, arrayA, arrayB)){
            answer = i;
            break;
        }
    }
    
    for(int i = arrayB[0]; i>1; i--){
        if(i < answer) return answer;
        if(isDevided(i, arrayB, arrayA)){
            return max(i, answer);
        }
    }
    return answer;
}