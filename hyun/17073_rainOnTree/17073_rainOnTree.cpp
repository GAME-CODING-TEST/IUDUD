// - 백준 17073 : 나무 위의 빗물

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,W; // 입력

vector<int> v[500001]; // 노드
int endNode = 0; // 리프 노드
bool visited[500001] = {false,}; // 방문 확인

// 관계 만들고 리프 노드 찾기
void makeTree(int sx){
    visited[sx] = 1; // 1번 노드 체크
    queue<int> q;
    q.push(sx);
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++){
            int nx = v[x][i];
            // 이미 방문한 노드에 부딪혔을 때
            if(visited[nx]) {
                // 자기 자신과 연결된 노드가 하나 뿐이라면
                if(v[x].size() == 1) endNode++; // 리프 노드 + 1
                continue;
            }
            visited[nx] = true;
            q.push(nx);
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> W;
    for(int i = 0; i < N-1; i++){
        int v1,v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    visited[1] = true;
    makeTree(1);
    cout.precision(10); // 출력 형식을 맞춰주기 위한 것
    cout << W / (double)endNode; // 소숫점 정밀도를 위한 double
}