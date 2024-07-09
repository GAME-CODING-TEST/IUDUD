#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 유클리드 호제법 사용
int gcd(int a, int b){
    int A = max(a,b);
    int B = min(a,b);
    
    while(A%B!=0){
        int R = A%B;
        A = B;
        B = R;
    }
    
    return B;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i<arr.size(); i++){
        int g = gcd(arr[i], answer);
        int l = answer * arr[i] / g;
        answer = l;
    }
    
    return answer;
}