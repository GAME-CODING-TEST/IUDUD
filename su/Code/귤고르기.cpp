#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> delicious;
    for(int i = 0; i<tangerine.size(); i++){
        delicious[tangerine[i]]++;
    }
    
    vector<int> count;
    for(auto a : delicious){
        count.push_back(a.second);
    }    
    
    sort(count.begin(), count.end(), greater<>());
    
    for(int i = 0; i<count.size(); i++){
        k-= count[i];
        if(k <= 0){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}