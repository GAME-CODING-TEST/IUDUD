#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    queue<int> num;
    num.push(arr[0]);
    for(int i = 1; i<arr.size(); i++){
        if(arr[i-1] != arr[i])
            num.push(arr[i]);
    }
    
    while(!num.empty()){
        answer.push_back(num.front());
        num.pop();
    }

    return answer;
}