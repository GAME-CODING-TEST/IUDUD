#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // 작은 순서 배열 * 큰 순서 배열
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    // 순서대로 곱하기
    for(int i = 0; i<A.size(); i++){
        answer += A[i]*B[i];
    }

    return answer;
}