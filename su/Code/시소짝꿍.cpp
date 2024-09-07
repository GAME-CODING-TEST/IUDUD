#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int MAX = 2001;
    long long dp[2001]{0};
    bool visit[2001]{false};
    
    for(auto i : weights)   dp[i]+=1;
    for(auto i : weights){
        if(dp[i] > 1 && !visit[i]){
            answer += dp[i]*(dp[i]-1)/2;
            visit[i] = true;
        }
        
        if(2*i<MAX && dp[2*i])  answer += dp[i*2];
        if(i%3==0 && i/3*4<MAX && dp[i/3*4])  answer += dp[i/3*4];
        if(i%2==0 && i/2*3<MAX && dp[i/2*3])  answer += dp[i/2*3];
    }
    
    return answer;
}