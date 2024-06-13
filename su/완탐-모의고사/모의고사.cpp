#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int AnswerCheck(int a, int b){
    return a==b? 1 : 0;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> solution1 = {1,2,3,4,5};
    vector<int> solution2 = {2,1,2,3,2,4,2,5};
    vector<int> solution3 = {3,3,1,1,2,2,4,4,5,5};
    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    
    for(int i = 0; i<answers.size(); i++){
        answer1 += AnswerCheck(solution1[i%solution1.size()], answers[i]);
        answer2 += AnswerCheck(solution2[i%solution2.size()], answers[i]);
        answer3 += AnswerCheck(solution3[i%solution3.size()], answers[i]);
    }
    
    int max_score = max({answer1, answer2, answer3});

    if (answer1 == max_score) answer.push_back(1);
    if (answer2 == max_score) answer.push_back(2);
    if (answer3 == max_score) answer.push_back(3);
    
    return answer;
}

