#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    // K만큼 점프 : 배터리 K만큼 소모
    // 순간이동 : 현재 거리 X2
    
    while(n>0){
        // 홀수인 경우
        if(n%2 == 0){
            n/=2;
        }else{
            // 점프
            n--;
            ans++;
        }
    }

    return ans;
}