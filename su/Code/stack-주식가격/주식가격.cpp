#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> second;
    
    for(int i = 0; i<size; i++){
        //second.top()이 없어서 앞으로 못 뺌
        while(!second.empty()&&prices[second.top()] > prices[i]){
            int top = second.top();
            answer[top] = i-top;
            second.pop();
        }
        second.push(i);
    }
    
    while(!second.empty()){
        int top = second.top();
        answer[top] = size-top-1;
        second.pop();
    }
    
    return answer;
}