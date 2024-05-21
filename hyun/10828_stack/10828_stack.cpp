// 백준 : 10828 스택

#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<int> st;    // 스택
  int N;            // 명령의 수
  string command;   // 명령어
  int num;          // push연산 시, 스택에 넣을 정수
  int result = 0;   // 각 명령어에 대한 결과 값

  cin >> N;

  for(int i = 0; i < N; i++)
  {
    cin >> command;

    // 1. push
    if ( command == "push" )
    {
      cin >> num;
      st.push(num);
    }

    // 2. pop
    // 스택이 비어있으면 -1 출력, 그 외는 top 값을 출력 후 pop
    else if ( command == "pop" )
    {
      if ( st.size() == 0 )
      {
        result = -1;
        cout << result << '\n';
      }

      else
      {
        result = st.top();
        cout << result << '\n';
        st.pop();
      }
    }

    // 3.size
    else if ( command == "size" )
    {
      cout << st.size() << '\n';
    }

    // 4. empty
    else if ( command == "empty" )
    {
      if ( st.size() == 0 )
      {
        result = 1;
        cout << result << '\n';     
      }

      else
      {
        result = 0;
        cout << result << '\n';
      }
    }

    // 5. top
    else if ( command == "top")
    {
      if ( st.size() == 0 )
      {
        result = -1;
        cout << result << '\n';
      }

      else 
      {
        result = st.top();
        cout << result << '\n';
      }
    }

  }

  return 0;
}