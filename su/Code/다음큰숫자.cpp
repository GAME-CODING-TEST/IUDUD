#include <string>
#include <vector>

using namespace std;

int binary(int n){
    int cnt = 0;
    while(n!=0){
        // 2로 나누어지지 않으면 1
        if(n%2 == 1) cnt++;
        n/=2;
    }
    
    return cnt;
}

int solution(int n) {
    int num = binary(n);
    n++;
    
    while(binary(n) != num){
        n++;
    }
    return n;
}
