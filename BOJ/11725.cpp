#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> parent;  // 각 노드의 부모를 저장할 map

// DFS 함수: 현재 노드 cur에서 시작
void solve(const vector<vector<int>>& tree, int cur) {
    for (int next : tree[cur]) {
        if (parent[next] == 0) {  // 아직 부모가 설정되지 않은 노드만 탐색
            parent[next] = cur;   // 현재 노드를 부모로 설정
            solve(tree, next);    // 재귀적으로 자식 노드 탐색
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);  // 트리를 인접 리스트로 표현 (1-based index)

    // 트리 간선 입력
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    parent[1] = 1;  // 루트 노드 1의 부모를 자기 자신으로 설정
    solve(tree, 1); // DFS로 탐색 시작

    // 2번 노드부터 부모 출력
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}