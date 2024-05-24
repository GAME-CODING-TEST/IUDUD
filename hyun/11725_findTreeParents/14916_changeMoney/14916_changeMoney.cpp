// - 백준 14916 : 거스름 돈

#include <iostream>

using namespace std;

int n;
int result = -1;

int main()
{
  cin >> n;

  int start = n / 5;
  int remain = (n - start * 5) % 2;
  
  while (remain != 0)
  {
    if (start == 0)
    {
      cout << -1;
      return 0;
    }

    start -= 1;
    remain = (n - start * 5) % 2;
  }

  cout << start + (n - start * 5) / 2;

  return 0;
}