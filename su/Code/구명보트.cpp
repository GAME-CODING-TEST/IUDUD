#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0;
    int end = people.size() - 1;

    // 무게순으로 정렬
    sort(people.begin(), people.end(), greater<>());

    while(start <= end){
        if(people[start] + people[end] <= limit){
            // 가벼운 사람 태움
            end--;
        }
        // 무거운 사람은 항상 태움
        start++;
        answer++;
    }

    return answer;
}
