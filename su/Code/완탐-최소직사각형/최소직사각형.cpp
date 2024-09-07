#include <string>
#include <vector>

using namespace std;
int CompSize(int a, int b);

int solution(vector<vector<int>> sizes) {    
    int small = 0;
    int big = 0;
    
    for(int i = 0; i<sizes.size(); i++){
        if(sizes[i][0]>sizes[i][1]){
            small = CompSize(sizes[i][1], small);
            big = CompSize(sizes[i][0], big);
        }else{
            small = CompSize(sizes[i][0], small);
            big = CompSize(sizes[i][1], big);
        }
    }
    
    return small * big;
}

// 더 큰 사이즈 리턴
int CompSize(int a, int b){
    if(a>b)return a;
    return b;
}