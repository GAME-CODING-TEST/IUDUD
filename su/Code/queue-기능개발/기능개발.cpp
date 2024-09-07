#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progress;
    int size = progresses.size();
    for(int i = 0; i<size; i++){
        progress.push(i);
    }
    while(!progress.empty()){
        int cnt = 0;
        
        for(int i = 0; i<size; i++){
            progresses[i] += speeds[i];
        }
        
        while(!progress.empty()&&progresses[progress.front()] >= 100){
            cnt++;
            progress.pop();
        }
        if(cnt!=0){
            answer.push_back(cnt);
        }
    }
    
    return answer;
}
