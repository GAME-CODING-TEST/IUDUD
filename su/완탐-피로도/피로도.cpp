#include <iostream>
#include <string>
#include <vector>

using namespace std;

void tired(vector<vector<int>> dungeons, vector<bool> visit, int cur, int curCnt, int& answer){
    // 최소 필요 피로도 체크
    answer = max(answer, curCnt);

    for(int i = 0; i<dungeons.size(); i++){
        if(visit[i])continue;
        if(cur >= dungeons[i][0]) {
            // 현재 피로도 - 던전 피로도
            visit[i] = true;
            tired(dungeons, visit, cur - dungeons[i][1], curCnt+1, answer);
            visit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visit(dungeons.size(), false);
    tired(dungeons, visit, k, 0, answer);
    return answer;
}