#include<iostream>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visited;  // 방문 여부를 체크하는 배열

// DFS 함수: 현재 노드에서 다른 노드들까지의 거리를 계산
void dfs(int cur, vector<int>& dist) {
    int len = tree[cur].size();
    for (int i = 0; i < len; i++) {
        int next_node = tree[cur][i].first;
        int weight = tree[cur][i].second;
        if (visited[next_node]) continue;  // 이미 방문한 노드는 건너뜀
        visited[next_node] = true;  // 방문 표시
        dist[next_node] = dist[cur] + weight;  // 다음 노드까지의 거리 계산
        dfs(next_node, dist);  // 재귀적으로 탐색
    }
}

int solve() {
    int max_node = 1;
    vector<int> dist(tree.size(), 0);  // 노드 간의 거리를 저장하는 배열
    visited.assign(tree.size(), false);  // 방문 배열 초기화
    visited[1] = true;  // 루트 노드 방문 표시

    // 첫 번째 DFS: 루트(1번 노드)에서 가장 먼 노드를 찾음
    dfs(1, dist);

    // dist에서 가장 먼 노드를 찾음
    int max_dist = 0;
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            max_node = i;  // 가장 먼 노드 저장
        }
    }

    // 두 번째 DFS를 위한 준비
    dist.assign(tree.size(), 0);  // 거리 배열 초기화
    visited.assign(tree.size(), false);  // 방문 배열 초기화
    visited[max_node] = true;  // max_node에서 시작

    // 두 번째 DFS: max_node에서 다시 가장 먼 노드를 찾음
    dfs(max_node, dist);

    // 두 번째 DFS에서의 최장 거리를 찾음
    max_dist = 0;
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];  // 최장 거리 값 저장
        }
    }

    return max_dist;  // 트리의 지름 반환
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    tree.resize(n + 1);  // 노드 개수에 맞게 트리 사이즈 조정

    // 트리의 간선 입력 받기
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x].push_back({y, z});
        tree[y].push_back({x, z});
    }

    // 트리의 지름 출력
    cout << solve() << '\n';
    return 0;
}