#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> s;
    int len = elements.size();
    vector<int> element(elements);
    copy(element.begin(), element.end(), back_inserter(elements));
    
    for(int i = 0; i<len; i++){
        int sum = elements[i];
        s.insert(sum);
        int cnt = 1;
        int end = i;
        while(cnt < len){
            cnt +=1;
            end += 1;
            sum += elements[end];
            s.insert(sum);
        }
    }
    
    answer = s.size();
    
    return answer;
}