// 백준 1620 : 나는야 포켓몬 마스터 이다솜

# include <iostream>
#include <string>
# include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
  
  int N;                    // 포켓몬 수
  int M;                    // 맞춰야 하는 문제의 수
  string pokemonList[100001];  // 포켓몬의 이름이 담기는 배열
  map<string, int> pokemon; // 맵을 사용해 포켓몬 이름에 해당하는 번호 부여

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    string name;
    cin >> name;
    
    pokemon.insert({name, i});
    pokemonList[i] = name;
  }

for (int i = 0; i < M; i++)
{
  string problem;
  cin >> problem;

  if (isdigit(problem[0]))
  {
    cout << pokemonList[stoi(problem)] << '\n';
  }

  else
  {
    cout << pokemon.find(problem)->second << '\n';
  }
}

  return 0;
}