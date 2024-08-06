#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cnt = 0;
    
    cnt = stations[0]-w-1>0?stations[0]-w-1:0;
    answer += cnt/(2*w+1);
    answer += cnt%(2*w+1)!=0?1:0;
    
    for(int i = 1; i<stations.size(); i++){
        cnt = stations[i]-stations[i-1]-2*w-1>0?stations[i]-stations[i-1]-2*w-1:0;
        answer += cnt/(2*w+1);
        answer += cnt%(2*w+1)!=0?1:0;
    }
    
    cnt = n+1 - stations.back()-w-1>0?n+1 - stations.back()-w-1:0;
    answer += cnt/(2*w+1);
    answer += cnt%(2*w+1)!=0?1:0;


    return answer;
}