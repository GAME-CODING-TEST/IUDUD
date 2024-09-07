#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> ponket;
    int n = nums.size();
    
    for(int i = 0; i<n; i++){
        ponket.insert(nums[i]);
    }
    
    if(ponket.size() < n/2)
        return ponket.size();
    
    return n/2;
}