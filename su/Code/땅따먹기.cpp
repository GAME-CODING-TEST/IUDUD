#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> result = land;
    
    for(int i = 1; i<land.size(); i++){
        for(int j = 0; j<land[i].size(); j++){
            for(int k = 0; k<land[i].size(); k++){
                if(j!=k){
                    result[i][j] = max(result[i][j], result[i-1][k] + land[i][j]);
                    answer = max(answer, result[i][j]);
                }
            }
        }
    }

    return answer;
}