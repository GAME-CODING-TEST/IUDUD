#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int answer = INT32_MAX;

int mining(int cnt, int idx, vector<int> mine){
    int pick = (int)pow(5,2-idx), res = 0;
    
    for(int i = cnt * 5; i<(cnt+1)*5&&i<mine.size(); i++){
        int num = mine[i]/pick;
        if(num==0){
            res++;
        }
        else{
            res += num;
        }
    }
    return res;
}

void dfs(int cnt, int res, vector<int> picks, vector<int> mine){
    if((!picks[0]&&!picks[1]&&!picks[2]) || cnt*5 >= mine.size()){ // 곡괭이 다 썼거나 광물을 다캠
        //cout << res << endl;
        answer = min(answer, res); // 최소저장
        return;
    }
    for(int i = 0; i<3; i++){
        if(picks[i]){
            picks[i]--;// 곡괭이 갯수
            dfs(cnt+1, res+mining(cnt, i, mine), picks, mine);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    vector<int> mine;
    for(auto c: minerals){
        if(c[0] == 'd') mine.push_back(25);
        else if(c[0] == 'i') mine.push_back(5);
        else mine.push_back(1);
    }
    dfs(0,0,picks, mine);
    
    return answer;
}