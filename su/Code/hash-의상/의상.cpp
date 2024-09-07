#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(auto cloth : clothes){
        m[cloth.first]++;
    }
    
    for(auto p:m){
        answer*=(p.second+=1);
    }
    return answer-1;
}