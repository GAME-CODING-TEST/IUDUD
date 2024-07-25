#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> complete(progresses.size(), 0);
    
    for(int i = 0; i<progresses.size(); i++){
        int progress = (100-progresses[i]);
        complete[i] = progress%speeds[i]!=0 ?(progress/speeds[i])+1:(progress/speeds[i]);
    }
    
    int tmp = complete[0];
    int ans = 1;
    for(int i = 1; i<progresses.size(); i++){
        // 해당 시간보다 진행 시간이 빠르면 계속
        if(tmp >= complete[i]){
            ans++;
        }
        else{
            answer.push_back(ans);
            ans = 1;
            tmp = complete[i];
        }
    }
    answer.push_back(ans);
    return answer;
}
