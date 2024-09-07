#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int>& cards, int idx, int sum){
    if(cards[idx]==0) return sum;
    int cur = cards[idx];
    cards[idx] = 0;
    return dfs(cards, cur-1,sum+1);
}

int solution(vector<int> cards) {
    vector<int> answer;
    
    for(int i = 0; i<cards.size(); i++){
        if(cards[i] == 0) continue;
        int cnt = dfs(cards, i, 0);
        answer.push_back(cnt);
    }
    
    sort(answer.rbegin(), answer.rend());
    if(answer.size()==1) return 0;
    else    return answer[0]*answer[1];
}