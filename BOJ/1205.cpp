#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, score, p;
    cin >> n >> score >> p;

    vector<int> ranking;

    if (n > 0) {
        ranking.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> ranking[i];
        }
    }

    // 1. 리스트가 비어있을 때, 무조건 1등
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }

    // 2. 리스트가 꽉 찼을 때
    if (n == p && score <= ranking.back()) {
        cout << -1 << '\n';  // 리스트가 꽉 차고 새로운 점수가 작으면 들어갈 수 없음
        return 0;
    }

    int rank = 1;  // 등수
    for (int i = 0; i < n; i++) {
        if (ranking[i] > score) {
            rank++;
        } else if (ranking[i] == score) {
            break;  // 동점이면 현재 rank 그대로
        } else {
            break;  // score가 더 크면, 현재 위치가 rank
        }
    }

    cout << rank << '\n';  // 계산된 rank 출력
    return 0;
}
