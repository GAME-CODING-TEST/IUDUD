#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> s;
    
    for(int i = numbers.size()-1; i>=0; i--){        
        while(1){
            if(s.empty()){
                answer[i] = -1;
                break;
            }
            if(s.top() > numbers[i]){
                answer[i]=s.top();
                break;
            }
            s.pop();
        }
        s.push(numbers[i]);
    }
    
    return answer;
}