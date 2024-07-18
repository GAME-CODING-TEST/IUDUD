#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution1(vector<int> arr1, vector<int> arr2) {
    int answer = 0;

    if (arr1.size() > arr2.size()) {
        answer = 1;
    }
    else if (arr1.size() < arr2.size()) {
        answer = -1;
    }
    else {
        int sum1 = accumulate(arr1.begin(), arr1.end(), 0);
        int sum2 = accumulate(arr2.begin(), arr2.end(), 0);
        answer = (sum1 > sum2) ? 1 : ((sum1 == sum2) ? 0 : -1);
    }

    return answer;
}

int solution2(vector<int> arr1, vector<int> arr2) 
{
    if (arr1.size() != arr2.size()) {
        return arr1.size() > arr2.size() ? 1 : -1;
    }

    int sum1 = accumulate(arr1.begin(), arr1.end(), 0);
    int sum2 = accumulate(arr2.begin(), arr2.end(), 0);
    return sum1 > sum2 ? 1 : ( sum1 == sum2 ? 0 : -1 );
}

int main()
{

}